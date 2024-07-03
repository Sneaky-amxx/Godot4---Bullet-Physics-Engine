
#ifndef __VOLUME_SOURCE_TREE_H_
#define __VOLUME_SOURCE_TREE_H_

#include "cube_tree.h"
#include "volume_source_gd.h"

namespace Ign
{

class VolumeSourceTree: public VolumeSource
{
public:
    typedef Ref<VolumeSourceGd> Src;

    VolumeSourceTree();
    virtual ~VolumeSourceTree();

    void set_max_depth( int d );
    int  get_max_depth() const;

    void set_max_items_per_node( int qty );
    int  get_max_items_per_node() const;

	virtual Float value( const Vector3d & at ) override;

	virtual Float max_node_size() const override;
	virtual Float min_node_size() const override;
	virtual Float max_node_size_local( const Vector3d & at ) override;
	virtual Float min_node_size_local( const Vector3d & at ) override;

	virtual int material( const Vector3d & at, int * priority = nullptr );

    void clear();
    void add_source( const Src & source );

    void subdivide( Float total_max_size=-1.0 );
    int nodes_qty() const;

public:
    CubeTree    tree;
    std::vector<Src> sources;
	Float _max_node_size;
	Float _min_node_size;
};

}





#endif


