#include "testApp.h"
#include "stdio.h"
#include "ofUtils.h"
//--------------------------------------------------------------
void testApp::setup(){

	tbeta = new ofxNCoreVision();
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	//draw blobs
	std::map<int, Blob> blobs;
	std::map<int, Blob>::iterator iter;
    blobs = tbeta->getBlobs(); //get blobs from tracker
	for(iter=blobs.begin(); iter!=blobs.end(); iter++)
	{
		Blob drawBlob;
		drawBlob = iter->second;
		ofSetColor(drawBlob.color);
		ofFill();
		ofEllipse( (drawBlob.centroid.x - drawBlob.boundingRect.width/2) * ofGetWidth() , 
				   (drawBlob.centroid.y - drawBlob.boundingRect.height/2) * ofGetHeight(),
				    drawBlob.boundingRect.width * ofGetWidth(), 
				    drawBlob.boundingRect.height * ofGetHeight());
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}

/*****************************************************************************
 *	TOUCH EVENTS
 *****************************************************************************/
void testApp::TouchDown( Blob b)
{
	b.color = 0xFF0000;
  //  ofSetColor(0xFF0000);
   /* ofFill();
	ofEllipse( (b.centroid.x - b.boundingRect.width/2) * ofGetWidth() , (b.centroid.y - b.boundingRect.height/2) * ofGetHeight(),
		       b.boundingRect.width * ofGetWidth(), b.boundingRect.height * ofGetHeight());
   */
}

void testApp::TouchUp( Blob b)
{	
	b.color = 0xFFFFFF;
    //ofSetColor(0x0FFFFF);
   /* ofFill();
	ofEllipse( (b.centroid.x - b.boundingRect.width/2) * ofGetWidth() , (b.centroid.y - b.boundingRect.height/2) * ofGetHeight(),
		       b.boundingRect.width * ofGetWidth(), b.boundingRect.height * ofGetHeight());
   */
}

void testApp::TouchMoved( Blob b)
{
	b.color = 0xFFFF00;
	//ofSetColor(0xFFFFFF);
   /* ofFill();
	ofEllipse( (b.centroid.x - b.boundingRect.width/2) * ofGetWidth() , (b.centroid.y - b.boundingRect.height/2) * ofGetHeight(),
		       b.boundingRect.width * ofGetWidth(), b.boundingRect.height * ofGetHeight());
   */
}

