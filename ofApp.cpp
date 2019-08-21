#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	auto height = 15;
	for (auto radius = 30; radius < 350; radius += 30) {

		ofPushMatrix();
		ofRotateZ(ofRandom(360));
		ofRotateY(ofRandom(360));
		ofRotateX(ofRandom(360));

		auto deg_start = ofGetFrameNum() * 5 + radius;
		auto deg_width = 120;

		ofFill();
		for (auto deg = deg_start; deg < deg_start + deg_width; deg += 3) {

			vector<glm::vec3> vertices;
			vertices.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), height * -0.5));
			vertices.push_back(glm::vec3(radius * cos((deg + 3) * DEG_TO_RAD), radius * sin((deg + 3) * DEG_TO_RAD), height * -0.5));
			vertices.push_back(glm::vec3(radius * cos((deg + 3) * DEG_TO_RAD), radius * sin((deg + 3) * DEG_TO_RAD), height * 0.5));
			vertices.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), height * 0.5));

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}

		vector<glm::vec3> line_1, line_2;
		for (auto deg = 0; deg < 360; deg++) {

			line_1.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), height * -0.5));
			line_2.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), height * 0.5));
		}

		ofNoFill();

		ofBeginShape();
		ofVertices(line_1);
		ofEndShape(true);

		ofBeginShape();
		ofVertices(line_2);
		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}