#include <maya/MFnPlugin.h>

#include "include/RippleDeformerNode.h"


MStatus initializePlugin(MObject obj)
{
    MFnPlugin plugin(obj, RippleDeformerNode::s_author, RippleDeformerNode::s_pluginVersion, RippleDeformerNode::s_mayaVersion);
    MStatus status = plugin.registerNode(RippleDeformerNode::s_commandName, RippleDeformerNode::id, RippleDeformerNode::creator, RippleDeformerNode::initialze, MPxNode::kDeformerNode);

    CHECK_MSTATUS_AND_RETURN_IT(status);
    return status;
}


MStatus uninitializePlugin(MObject obj)
{
    MFnPlugin plugin(obj);
    MStatus status = plugin.deregisterNode(RippleDeformerNode::id);

    CHECK_MSTATUS_AND_RETURN_IT(status);
    return status;
}
