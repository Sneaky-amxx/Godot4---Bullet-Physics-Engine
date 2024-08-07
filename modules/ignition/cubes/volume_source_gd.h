
#ifndef __VOLUME_SOURCE_GD_H_
#define __VOLUME_SOURCE_GD_H_

#include "volume_source.h"
#include "marching_volume_object_gd.h"
#include "se3_ref.h"

namespace Ign
{

class VolumeSourceGd: public MarchingVolumeObjectGd
{
	GDCLASS(VolumeSourceGd, MarchingVolumeObjectGd);
protected:
	static void _bind_methods();

public:
	VolumeSourceGd();
	virtual ~VolumeSourceGd();

	real_t value( const Vector3 & at ) const;

	void set_inverted( bool en );
	bool get_inverted() const;

	void set_material_only( bool en );
	bool get_material_only() const;

	real_t max_node_size() const;
	real_t min_node_size() const;
	real_t max_node_size_local( const Vector3 & at ) const;
	real_t min_node_size_local( const Vector3 & at ) const;

	int material_global( const Vector3 & at );
	int material( const Vector3 & at );

	int priority() const;

public:
	VolumeSource * source;
	int last_priority;
};




}





#endif




