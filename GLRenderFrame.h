#ifndef GL_RENDER_FRAME_H
#define GL_RENDER_FRAME_H

#include <CImg.h>

using namespace cimg_library; 

namespace fireparrot
{
    /**
     * A simple rendering window using opengl to render a cimg.
     */
    class GLRenderFrame
    {
    private:
        /**
         * The fps we want our renderer to aim for.
         * Default value is 30
         */
        int m_targetFps;
        /**
         * Our local copy of the frame to be rendered
         */
        CImg<unsigned char> m_renderFrame;
        /**
         * x dimensions of the render frame
         */
        int m_frameWidth;
        /**
         * y dimensions of the render frame
         */
        int m_frameHeight;
        /**
         * is the frame set to render fullscreen?
         */
        bool m_frameFullscreen;
        /**
         * Controls execution of the main render loop
         */
        bool m_running;
        /**
         * Texture id of our opengl texture
         */ 
        GLuint m_textureId;
        /**
         * The main render loop
         */
        void RenderLoop();

    public:
        GLRenderFrame(int width, int height, bool fullscreen = false) throw (DroneException);
        virtual ~GLRenderFrame();

        /**
         * Updates the target fps
         */
        void SetTargetFPS(int targetFps) { m_targetFps = targetFps; }
        /**
         * Update the currently rendering frame
         */
        void GLRenderFrame::UpdateFrame(CImg<unsigned char> img);
    };
}

#endif
