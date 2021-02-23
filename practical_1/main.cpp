#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
    Keyboard::W,   // Player1 UP
    Keyboard::S,   // Player1 Down
    Keyboard::Up,  // Player2 UP
    Keyboard::Down // Player2 Down
};
const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;
Vector2f ballVelocity;
bool server = false;
bool AI = false;

CircleShape ball;
RectangleShape paddles[2];

void Load() {
    // Set size and origin of paddles
    for (auto& p : paddles) {
        p.setSize(paddleSize - Vector2f(3, 3));
        p.setOrigin(paddleSize / 2.f);
    }
    // Set size and origin of ball
    ball.setRadius(ballRadius);
    ball.setOrigin(ballRadius / 2, ballRadius / 2);
    // reset paddle position
    paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
    paddles[1].setPosition(790 - paddleSize.x / 2, gameHeight / 2);
    // reset Ball Position
    ball.setPosition(gameWidth / 2, gameHeight / 2);
    ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };
    // Load font-face from res dir
 //   font.loadFromFile("res/fonts/RobotoMono-Regular.ttf");
    // Set text element to use font
 //   text.setFont(font);
    // set the character size to 24 pixels
 //   text.setCharacterSize(24);
}

void Reset() {
    ball.setPosition(gameWidth / 2, gameHeight / 2);
    ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };
    // Update Score Text
 //   text.setString(...);
    // Keep Score Text Centered
 //   text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void Update(RenderWindow& window) {
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    // check and consume events
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    // handle paddle movement
    float direction = 0.0f;
    if (Keyboard::isKeyPressed(controls[0])) {
        direction--;
    }
    if (Keyboard::isKeyPressed(controls[1])) {
        direction++;
    }
    paddles[0].move(0, direction * paddleSpeed * dt);
    if (paddles[0].getPosition().y - (paddleSize.y / 2) < 0) {
        paddles[0].setPosition(paddles[0].getPosition().x, paddleSize.y / 2);
    }
    if (paddles[0].getPosition().y + (paddleSize.y / 2) > gameHeight) {
        paddles[0].setPosition(paddles[0].getPosition().x, gameHeight - (paddleSize.y / 2));
    }
    direction = 0.0f;
    if (Keyboard::isKeyPressed(controls[2])) {
        direction--;
    }
    if (Keyboard::isKeyPressed(controls[3])) {
        direction++;
    }
    if (AI == true) {
        if (ball.getPosition().y < paddles[1].getPosition().y) {
            direction--;
        }
        if (ball.getPosition().y > paddles[1].getPosition().y) {
            direction++;
        }
    }
    paddles[1].move(0, direction* paddleSpeed* dt);
    if (paddles[1].getPosition().y - (paddleSize.y / 2) < 0) {
        paddles[1].setPosition(paddles[1].getPosition().x, paddleSize.y / 2);
    }
    if (paddles[1].getPosition().y + (paddleSize.y / 2) > gameHeight) {
        paddles[1].setPosition(paddles[1].getPosition().x, gameHeight - (paddleSize.y / 2));
    }
    ball.move(ballVelocity * dt);

    // check ball collision
    const float bx = ball.getPosition().x;
    const float by = ball.getPosition().y;
    if (by > gameHeight) { //bottom wall
      // bottom wall
        ballVelocity.x *= 1.1f;
        ballVelocity.y *= -1.1f;
        ball.move(0, -10);
    }
    else if (by < 0) { //top wall
   // top wall
        ballVelocity.x *= 1.1f;
        ballVelocity.y *= -1.1f;
        ball.move(0, 10);
    }
    else if (bx > gameWidth) {
        // right wall
        Reset();
    }
    else if (bx < 0) {
        // left wall
        Reset();
    }
    else if (
        //ball is inline or behind paddle
        bx < paddleSize.x &&
        //AND ball is below top edge of paddle
        by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
        //AND ball is above bottom edge of paddle
        by < paddles[0].getPosition().y + (paddleSize.y * 0.5)
        ) {
        // bounce off left paddle
        ballVelocity.x *= -1.1f;
        ball.move(20, 0);
    }
    else if (bx > (gameWidth - paddleSize.x) && by > paddles[1].getPosition().y - (paddleSize.y * 0.5) && by < paddles[1].getPosition().y + (paddleSize.y * 0.5)) {
        // bounce off right paddle
        ballVelocity.x *= -1.1f;
        ball.move(-20, 0);
    }
}

void Render(RenderWindow& window) {
    // Draw Everything
    window.draw(paddles[0]);
    window.draw(paddles[1]);
    window.draw(ball);
}

int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}