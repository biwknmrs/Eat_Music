#include "ofApp.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //(facetracker)
    ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    
	search_PT.x=400;
    search_PT.y=300;
	viewer_PT.x=400;
    viewer_PT.y=768;
    
	cam.initGrabber(search_PT.x,search_PT.y);//顔検出に使うカメラの解像度
    //graycamera.setFromPixels(cam.getPixels(), 320, 768);
	tracker.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    if(cam.isFrameNew()) {
		tracker.update(ofxCv::toCv(cam));
        
    }
    mouth_PT.x=0;
    mouth_PT.y=0;
    
    for(int i=0;i<tracker.size();i++){
        mouth_PT=mouth_PT+tracker.getImagePoint(i)/tracker.size();
    }
    
    
    //mouth_PT = (tracker.getImagePoint(61)+tracker.getImagePoint(64)-(320,240));
    mouth_PT.x=mouth_PT.x*(viewer_PT.x/search_PT.x);//口の座標を再計算
    mouth_PT.y=mouth_PT.y*(viewer_PT.y/search_PT.y);//口の座標を再計算
    //graycamera.setFromPixels(cam.getPixels(), 320, 768);
    //(アニメーション)
    //(ここまで)
}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.draw(0, 0,viewer_PT.x,viewer_PT.y);//実際の書き出し
    //ofRect(mouth_PT, 100,100);//デバック用
    time++;
    gakuhu.update(time,60);
    gakuhu.draw();
	
	if(tracker.getFound()) {
        mouth_height = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT);
        
        /*
		ofSetLineWidth(1);
        tracker.getImageFeature(tracker.INNER_MOUTH).draw();
        tracker.getImageFeature(tracker.OUTER_MOUTH).draw();
        */
        
        if (mouth_height >= 2.0){
            ofDrawBitmapString("open!!", 10, 20);
            
            for (int i = 0; i < onpu_sum; i++){
                
                
                
                Atarihantei hantei = *new Atarihantei();
            if(hantei.atarihantei(gakuhu.onpu_PT[i]+100, mouth_PT, i) == 1){
                //ok
                    
                switch (gakuhu.takasa[i]) {
                    case 'C':
                        sound[i].loadSound("scale/c.mp3");
                        sound[i].play();
                        break;
                    case 'D':
                        sound[i].loadSound("scale/d.mp3");
                        sound[i].play();
                        break;
                    case 'E':
                        sound[i].loadSound("scale/e.mp3");
                        sound[i].play();
                        break;
                    case 'F':
                        sound[i].loadSound("scale/f.mp3");
                        sound[i].play();
                        break;
                    case 'G':
                        sound[i].loadSound("scale/g.mp3");
                        sound[i].play();
                        break;
                        
                    default:
                        break;
                }
                gakuhu.destroy(i);
                
                    
            }else{
                //miss
            }
            }

        }else if(mouth_height < 2.0){
            ofDrawBitmapString("close...", 10, 20);
        }
    }else{
        ofDrawBitmapString("serching for face...", 10, 20);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 't'){
        tracker.reset();
    }
    if(key == 'r'){

    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}