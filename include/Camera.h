#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
    public:
        Camera();
        virtual ~Camera();
        void WalkWithPlayer(int playerX, int playerY);
        int w = 0;
        int h = 0;
        float x = 0;
        float y = 0;
    protected:
    private:
};

#endif // CAMERA_H
