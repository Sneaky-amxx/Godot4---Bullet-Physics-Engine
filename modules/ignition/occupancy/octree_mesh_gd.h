
#include "scene/main/node.h"
#include "scene/3d/mesh_instance_3d.h"

#include "octree_mesh.h"
#include "se3_ref.h"

namespace Ign
{

class OctreeMeshGd: public Node
{
    GDCLASS(OctreeMeshGd, Node);
    //OBJ_CATEGORY("Ignition");

protected:
    static void _bind_methods();
	void _notification(int p_notification);
public:
    OctreeMeshGd();
    ~OctreeMeshGd();

	void set_max_depth( int val );
	int get_max_depth() const;
	void set_min_faces( int val );
	int get_min_faces() const;

    void set_origin( const Vector3 & at );
    const Vector3 & get_origin() const;

    void set_quat( const Quaternion & q );
    const Quaternion & get_quat() const;

    void set_se3( const Ref<Se3Ref> & rhs );
    Ref<Se3Ref> get_se3() const;

    void rebuild();
    int faces_qty();
    Array get_face( int ind );
	Array get_face_world( int ind );
	bool intersects_ray( const Vector3 & origin, const Vector3 & dir );
    Array intersects_ray_face( const Vector3 & origin, const Vector3 & dir );
    bool intersects_segment( const Vector3 & start, const Vector3 & end );
    Array intersects_segment_face( const Vector3 & start, const Vector3 & end );

    OctreeMesh * octree_mesh();
	const OctreeMesh * octree_mesh() const;

private:
    OctreeMesh _octree_mesh;
    Array      _ret_array;
};

}

