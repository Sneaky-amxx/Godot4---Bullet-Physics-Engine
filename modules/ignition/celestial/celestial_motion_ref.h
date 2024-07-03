
#ifndef __CELESTIAL_MOTION_REF_H_
#define __CELESTIAL_MOTION_REF_H_

#include "core/object/ref_counted.h"
#include "scene/3d/node_3d.h"

#include "se3_ref.h"
#include "celestial_motion.h"
#include "scale_distance_ratio_gd.h"

namespace Ign
{

class RefFrameNode;

class CelestialMotionRef: public RefCounted
{
    GDCLASS( CelestialMotionRef, RefCounted );
    //OBJ_CATEGORY("Ignition");

protected:
    static void _bind_methods();

public:
    CelestialMotionRef();
    ~CelestialMotionRef();

    void set_allow_orbiting( bool en );
    bool get_allow_orbiting() const;

    void stop();

    bool is_orbiting() const;
    String movement_type() const;
    real_t specific_angular_momentum() const;
    real_t eccentricity() const;
    real_t period() const;
    real_t time_after_periapsis() const;
    real_t closest_approach() const;
    real_t perigee() const;
    real_t apogee() const;
    real_t min_velocity() const;
    real_t max_velocity() const;
    real_t excess_velocity() const;
    real_t deflection_angle() const;
	Vector3 acceleration() const;
	// Orbit orientation.
    // From focus towards perigee.
    Vector3 ex() const;
    // Along velocity at perigee.
    Vector3 ey() const;

    void set_se3( const Ref<Se3Ref> & se3 );
    Ref<Se3Ref> get_se3() const;

    real_t get_gm() const;

    bool launch( real_t gm, const Ref<Se3Ref> & se3 );
    real_t compute_gm_by_speed( real_t radius_km, real_t wanted_surface_orbit_velocity_kms ) const;
	real_t compute_gm_by_period( real_t radius_km, real_t wanted_period_kms ) const;
	void launch_elliptic( real_t gm, const Vector3 & unit_r, const Vector3 & unit_v, real_t period_hrs, real_t eccentricity );
    Ref<Se3Ref> process( real_t dt );
    void process_rf( real_t dt, Node * rf );

    Ref<CelestialMotionRef> duplicate() const;

    Dictionary serialize() const;
    bool deserialize( const Dictionary & data );

	Array orbit_points( Node * orbiting_center, Node * camera_node, int qty, const Ref<ScaleDistanceRatioGd> & scale_distance_ratio, real_t base_scale );

	void set_force_numerical( bool en );
	bool get_force_numerical() const;


	void set_debug( bool en );
	bool get_debug() const;

public:
    CelestialMotion cm;
	// This one is for trajectory visualization buffering.
	Vector<Vector3d> pts;
};


}



#endif




