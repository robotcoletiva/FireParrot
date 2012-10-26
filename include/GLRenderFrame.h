#ifndef GL_RENDER_FRAME_H
#define GL_RENDER_FRAME_H

#include <Common.h>
#include <CImg.h>

#include <thread>
#include <functional>

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
        int m_textureId;
        /**
         * The currently rendering frame
         */
        DroneFrame m_renderFrame;
        /**
         * The thread our render loop is running on
         */
        std::thread m_runningThread;
        /**
         * The main render loop
         */
        void RenderLoop();

        bool m_updatedFlag;

    public:
        GLRenderFrame(int width, int height, bool fullscreen = false) throw (DroneException);
        virtual ~GLRenderFrame();

        /**
         * Stops the render thread from running
         */
        void StopRender();
        /**
         * Starts the render frame
         */
        void StartRender();
        /**
         * Updates the target fps
         * \param targetFps The target fps
         */
        void SetTargetFPS(int targetFps) { m_targetFps = targetFps; }
        /**
         * Update the currently rendering frame
         * \param img A copy of the DroneFrame struct containing the image
         */
        void UpdateFrame(DroneFrame img);
    };
}

#endif
