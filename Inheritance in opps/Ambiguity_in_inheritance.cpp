#include <iostream>
using namespace std;

class Camera{
public:
    void start(){
        cout << "Camera is starting." << endl;
    }
};

class MusicPlayer{
public:
    void start(){
        cout << "Music player is starting." << endl;
    }
};

class Smartphone : public Camera, public MusicPlayer{
public:
    void usePhone(){
        Camera::start();
        MusicPlayer::start();
    }
};

int main(){
    Smartphone phone;

    phone.usePhone();

    return 0;
}