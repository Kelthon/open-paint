#ifndef APP_H
#define APP_H

#include <string>

typedef void (* Callback)(void);
typedef void (* MouseMotionCallback)(int x, int y);
typedef void (* KeyboardCallback)(unsigned char key, int x, int y);
typedef void (* MouseCallback)(int button, int state, int x, int y);

class App
{
    public:
        void run(int argc, char **argv);
        void init(int argc, char **argv);
        void setTitle(std::string title);
        void setMouseFunction(MouseCallback mouseFunction);
        void setMouseMotionFunction(MouseMotionCallback mouseFunction);
        void setKeyboardFunction(KeyboardCallback keyboardFunction);
        void setDisplayFunction(Callback displayFunction);
        void setSize(size_t width, size_t height);
//        void render(int primitive, float *color, float **vertex);
        App(std::string title, size_t width, size_t height);
        virtual ~App();

    private:
        char * title;
        size_t width;
        size_t height;
        Callback displayFunction;
        MouseCallback mouseFunction;
        KeyboardCallback keyboardFunction;
        MouseMotionCallback mouseMotionFunction;
};

#endif // APP_H
