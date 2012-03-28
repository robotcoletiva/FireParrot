#include <GLRenderFrame.h>
#include <GL/glfw.h>


namespace fireparrot
{
    GLRenderFrame::GLRenderFrame(int width, int height, bool fullscreen) throw(DroneException):
            m_frameWidth(width), m_frameHeight(height), m_frameFullscreen(fullscreen), 
            m_targetFps(30), m_running(false) 
    {
            }
    
    GLRenderFrame::~GLRenderFrame()
    {

    }

    void GLRenderFrame::StartRender()
    {
        m_running = true;
        // Start the render thread
        m_runningThread = std::thread(std::bind(&GLRenderFrame::RenderLoop, this));
    }
    
    void GLRenderFrame::StopRender()
    {
        m_running = false;
        m_runningThread.join();
    }

    void GLRenderFrame::UpdateFrame(DroneFrame img)
    {
        m_renderFrame = img;
    }

    void GLRenderFrame::RenderLoop()
    {
        if (glfwInit() != GL_TRUE)
        {
            throw DroneException("Unable to init glfw");
        }
        int mode = GLFW_WINDOW;
        if (m_frameFullscreen)
        {
            mode = GLFW_FULLSCREEN;
        }
        if (glfwOpenWindow(m_frameWidth, m_frameHeight, 0, 0, 0, 
                                        8, 0, 0, mode) != GL_TRUE)
        {
            throw DroneException("Unable to open gl window");
        }
        // Setup ortho view for 2d
        GLint iViewport[4];
        glGetIntegerv(GL_VIEWPORT, iViewport);
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(iViewport[0], iViewport[0]+iViewport[2], iViewport[1]
                                    +iViewport[3], iViewport[1], -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        // Disable some stuff we wont need for 2d rendering
        glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glDisable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
    
        // Setup gl texture
        glGenTextures(1, (GLuint*)&m_textureId);
        glBindTexture(GL_TEXTURE_2D, m_textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 640, 480, 0, GL_RGB, GL_UNSIGNED_BYTE, m_renderFrame.data());

        while (m_running)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 640, 480, 0, GL_RGB, GL_UNSIGNED_BYTE, m_renderFrame.data);
            
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_QUADS);
            glTexCoord2f(0, 480);
            glVertex2f(0, 0);
            glTexCoord2f(640, 480);
            glVertex2f(640, 0);
            glTexCoord2f(640, 0);
            glVertex2f(640, 480);
            glTexCoord2f(0, 0);
            glVertex2f(0, 480);
            glEnd();
            glfwSwapBuffers();
        }
        glfwTerminate();
    } 
}
