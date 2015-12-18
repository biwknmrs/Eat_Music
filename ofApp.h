#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"
#include "Gakuhu.h"
#include "Atarihantei.h"
#define NUM 20

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofSoundPlayer sound[100];
    int i;
    
    //(アニメーション)
    Gakuhu gakuhu;
    ofImage onpu_image[6];
    int time;
    //(ここまで)
    
    //(facetracker)
    ofVideoGrabber cam;
	ofxFaceTracker tracker;
	ofVec2f position;
	float scale;
	ofVec3f orientation;
	ofMatrix4x4 rotationMatrix;
	
	cv::Mat translation, rotation;
	ofMatrix4x4 pose;
	
	ofEasyCam easyCam;
    
    ofVec2f mouth_PT;
    float mouth_height;
    //(ここまで)

    ofVec2f search_PT;//実際顔検出しているカメラの座標
    ofVec2f viewer_PT;
    
};
