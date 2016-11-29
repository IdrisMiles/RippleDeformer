#include "include/RippleDeformerNode.h"

const char* RippleDeformerNode::s_commandName = "RippleDeformerNode";
const char* RippleDeformerNode::s_author = "Idris Miles";
const char* RippleDeformerNode::s_pluginVersion = "1.0";
const char* RippleDeformerNode::s_mayaVersion = "Any";
MObject RippleDeformerNode::a_offset;
MTypeId RippleDeformerNode::id(0x00000001);

void* RippleDeformerNode::creator()
{
    return new RippleDeformerNode();
}


RippleDeformerNode::RippleDeformerNode()
{
}


MStatus RippleDeformerNode::initialze()
{
    MFnNumericAttribute nAttr;
    a_offset = nAttr.create("offset", "ofs", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(a_offset);
    attributeAffects(a_offset, outputGeom);

    return MS::kSuccess;
}


MStatus RippleDeformerNode::deform(MDataBlock &block, MItGeometry &iter, const MMatrix &mat, unsigned int multiIndex)
{
    MStatus returnStatus;

    // Get envelope value - just a scale factor common with deformers
    MDataHandle envData = block.inputValue(envelope, &returnStatus);
    if(returnStatus != MS::kSuccess){return returnStatus;}
    float env = envData.asFloat();


    // Get our offset value
    MDataHandle ofsData = block.inputValue(a_offset, &returnStatus);
    if(returnStatus != MS::kSuccess){return returnStatus;}
    float offset = ofsData.asFloat();


    // Perform deformation on each point in geometry
    for(; !iter.isDone(); iter.next())
    {
        MPoint pt = iter.position();

        double displacement = sin(pt.y + (double)offset);

        pt.y += (env * displacement);

        iter.setPosition(pt);
    }


    return returnStatus;


}

