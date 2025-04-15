#include "freeglut.h"
#include <iostream>
#include "raton.h"

void ClickRaton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        std::cout << "Clic izquierdo en: (" << x << ", " << y << ")" << std::endl;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        std::cout << "Clic derecho en: (" << x << ", " << y << ")" << std::endl;
    }
}
