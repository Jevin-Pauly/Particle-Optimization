//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Node.h"
#include "JediColdNode.h"

// Insert code

void JediColdNode::copy(Node& othern)
{
    this->key = othern.key;
    this->aa = othern.aa;
    this->bb = othern.bb;
    this->cc = othern.cc;
    this->dd = othern.dd;
    this->x = othern.x;
    this->y = othern.y;
    this->z = othern.z;
    this->w = othern.w;
    this->A = othern.A;
    this->B = othern.B;
    this->C = othern.C;
    this->D = othern.D;
    this->MA = othern.MA;
    this->MB = othern.MB;
    this->MC = othern.MC;
    this->MD = othern.MD;
    this->ME = othern.ME;
    memcpy(this->name, othern.name, Node::NAME_SIZE);
    return;
}

// ---  End of File ---

