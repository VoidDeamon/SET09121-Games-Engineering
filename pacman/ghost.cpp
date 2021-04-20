//#include "ghost.h"
//#include "LevelSystem.h"
//#include "system_renderer.h"
//#include <iostream>
//
//using namespace sf;
//using namespace std;
//
//void Ghost::Update(double dt) {
//    //Move in four directions based on keys
//    float horizontalDirection = 0.0f;
//    float verticalDirection = 0.0f;
//    int temp1 = rand() % 1;
//    int temp2 = rand() % 1;
//    if (temp1 == 0) {
//        horizontalDirection--;
//    }
//    else {
//        horizontalDirection++;
//    }
//    if (temp2 == 0) {
//        verticalDirection--;
//    }
//    else {
//        verticalDirection++;
//    }
//    Vector2f position = getPosition();
//    move(Vector2f(horizontalDirection * _speed * dt, verticalDirection * _speed * dt));
//   /* if (ls::getTileAt(getPosition()) == 3) {
//        setPosition(position);
//    } */
//
//    Entity::Update(dt);
//}
//
//Ghost::Ghost()
//    : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
//    _shape->setFillColor(Color::Magenta);
//    _shape->setOrigin(Vector2f(25.f, 25.f));
//}
//
//void Ghost::Render() const {
//    //window.draw(*_shape);
//    Renderer::queue(_shape.get());
//}