
#include "volume_source.h"

namespace Ign
{

VolumeSource::VolumeSource()
    : MarchingVolumeObject() 
{
	inverted      = false;
	material_only = false;
}

VolumeSource::~VolumeSource()
{
}

Float VolumeSource::value_global( const Vector3d & at )
{
    const Vector3d local_at = se3_inverted * at;
    const Float v = value( local_at );
    return v;
}

Float VolumeSource::value( const Vector3d & at )
{
    const Float d = at.LengthSquared() - 5.0;
    return d;
}

void VolumeSource::set_inverted( bool en )
{
    inverted = en;
}

bool VolumeSource::get_inverted() const
{
    return inverted;
}

void VolumeSource::set_material_ony( bool en )
{
	material_only = en;
}

bool VolumeSource::get_material_only() const
{
	return material_only;
}

int VolumeSource::material_global( const Vector3d & at, int * priority )
{
	const Vector3d local_at = se3_inverted * at;
	const int m = material( local_at, priority );
	return m;
}

int VolumeSource::material( const Vector3d & at, int * priority )
{
	if ( priority != nullptr )
		*priority = 0;
	return 0;
}








}













