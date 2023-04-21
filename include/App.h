#ifndef APP_H
#define APP_H

#include <string>

typedef void (* callback)(void);

class App
{
    public:
        void run(int argc, char **argv);
        void init(int argc, char **argv);
        void setTitle(std::string title);
        void setDisplayFunction(callback displayFunction);
        void setSize(unsigned int width, unsigned int height);

        App();
        App(std::string title, unsigned int width, unsigned int height);
        virtual ~App();

    private:
        char * title;
        unsigned int width;
        unsigned int height;
        callback displayFunction;
};

#endif // APP_H
