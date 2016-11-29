#ifndef _RIPPLEDEFORMNODE__H_
#define _RIPPLEDEFORMNODE__H_

// Maya include
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MStatus.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MPoint.h>
#include <maya/MItGeometry.h>
#include <maya/MPxDeformerNode.h>


class RippleDeformerNode : public MPxDeformerNode
{
public:
    RippleDeformerNode();
    static void* creator();
    static MStatus initialze();
    virtual MStatus deform(MDataBlock &block, MItGeometry &iter, const MMatrix &mat, unsigned int multiIndex);

    static MTypeId id;
    static MObject a_offset;
    
    static const char* s_commandName;
    static const char* s_author;
    static const char* s_pluginVersion;
    static const char* s_mayaVersion;
};

#endif //_RIPPLEDEFORMNODE__H_
