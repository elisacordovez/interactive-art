#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    img.loadImage("Kirby.png");
    grabber.setup(1280, 800);
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
}

//--------------------------------------------------------------
void ofApp::update()
{
//    float threshold = 200;
    grabber.update();
    
    if (grabber.isFrameNew())  // yes?
    {
        // get the pixels from the camera
        grabberPix = grabber.getPixels();
        for (int x = 0; x < grabberPix.getWidth(); x++)
        {
            for (int y = 0; y < grabberPix.getHeight(); y++)
            {
                // and now we can do something!
                
                ofColor pixelColor = grabberPix.getColor(x, y);
                
//                float brightness = pixelColor.getBrightness();
//
//                // if it is above our threshold
//                if (brightness > threshold)
//                {
//                    // draw it white
//                    grabberPix.setColor(x, y, ofColor(255));
//                }
//                else // if it is below our threshold
//                {
//                    // do something else... like draw the pixel black
//                    grabberPix.setColor(x, y, ofColor(0));
//                }
                
                // get individual color compontes
                int red = pixelColor.r;
                int green = pixelColor.g;
                int blue = pixelColor.b;
                
                // create our swapped color
                ofColor swappedColor(red, blue, green);
                grabberPix.setColor(x, y, swappedColor);
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    // now we can iterate through our pixels
    for (int x = 0; x < grabberPix.getWidth(); x+=20)
    {
        for (int y = 0; y < grabberPix.getHeight(); y+=20)
        {
            ofColor pixelColor = grabberPix.getColor(x, y);
            float brightnessValue0 = pixelColor.getBrightness();
            float brightnessValue1 = pixelColor.getBrightness();
            float brightnessValue2 = pixelColor.getBrightness();
            float brightnessValue3 = pixelColor.getBrightness();
            
            brightnessValue0 = ofMap(brightnessValue0, 0, 200, 0, 3);
            brightnessValue1 = ofMap(brightnessValue1, 0, 200, 0, 10);
            brightnessValue2 = ofMap(brightnessValue2, 0, 200, 0, 300);
            brightnessValue3 = ofMap(brightnessValue3, 0, 200, 0, 15);
            
            ofSetColor(pixelColor);
            ofFill();
            
            ofPushMatrix();
            ofTranslate(grabber.getWidth()/2, 0);
            ofScale(-.5, .5, 1);
            
//            ofDrawCircle(x, y, brightnessValue);
            ofSetLineWidth(brightnessValue0);
            ofDrawLine(x, y, x+10, y+10);
//            img.draw(x, y, brightnessValue);
//            ofDrawTriangle(x, y, x+10, y+10, 100, 100);
//           ofDrawRectangle(x, y, brightnessValue0, brightnessValue0);
            //grabber.draw(0, 0);
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(grabber.getWidth(), 0);
            ofScale(-.5, .5, 1);
            
            //            ofDrawCircle(x, y, brightnessValue);
//            ofSetLineWidth(brightnessValue0);
            //           ofDrawLine(x, y, x+10, y+10);
            //            img.draw(x, y, brightnessValue);
            //            ofDrawTriangle(x, y, x+10, y+10, 100, 100);
            ofDrawRectangle(x, y, brightnessValue1, brightnessValue1);
            //grabber.draw(0, 0);
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(grabber.getWidth()/2, grabber.getHeight()/2);
            ofScale(-.5, .5, 1);
            
            //            ofDrawCircle(x, y, brightnessValue);
            //            ofSetLineWidth(brightnessValue0);
            //           ofDrawLine(x, y, x+10, y+10);
                        img.draw(x, y, brightnessValue2);
            //            ofDrawTriangle(x, y, x+10, y+10, 100, 100);
//            ofDrawRectangle(x, y, brightnessValue1, brightnessValue1);
            //grabber.draw(0, 0);
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(grabber.getWidth(), grabber.getHeight()/2);
            ofScale(-.5, .5, 1);
            
                        ofDrawCircle(x, y, brightnessValue3);
                        ofSetLineWidth(brightnessValue3);
                       ofDrawLine(x, y, x+10, y+10);
//            img.draw(x, y, brightnessValue2);
            //            ofDrawTriangle(x, y, x+10, y+10, 100, 100);
//                        ofDrawRectangle(x, y, brightnessValue3, brightnessValue3);
            //grabber.draw(0, 0);
            ofPopMatrix();
        }
    }
    
    //grabber.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
