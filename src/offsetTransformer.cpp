//
//  offsetTransformer.cpp
//  PolyMouse
//
//  Created by Tristan Hume on 2016-01-07.
//
//

#include "offsetTransformer.h"
#include "ofxRemoteUIServer.h"
#include <iostream>
using namespace std;

offsetTransformer::offsetTransformer(inputProcess<ofVec2f> *inp, std::string name)
  : inp(inp), name(name), scale(5.0) {}

void offsetTransformer::setup() {
  inp->setup();
  recenter();

  RUI_NEW_GROUP(name);
  RUI_SHARE_PARAM(scale, 0, 50);
  RUI_SHARE_PARAM(center.x, -50, 50);
  RUI_SHARE_PARAM(center.y, -50, 50);
}

void offsetTransformer::update() {
  inp->update();
  ofVec2f offset = inp->val - center;
  val = offset * scale;
  cout << "offset: " << val << endl;
}

void offsetTransformer::recenter() {
  center = inp->val;
}
