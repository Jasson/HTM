/*
 * =====================================================================================
 *
 *       Filename:  Space.h
 *
 *    Description:  
 *
 * =====================================================================================
 */

#ifndef  _HTM07_SPACE_H__INC
#define  _HTM07_SPACE_H__INC

#include <stdlib.h>
#include "Common.h"

namespace htm07 {

class SpaceT
{
public:
    SpaceT(const VecT *max);
    ~SpaceT();
    SpaceT(const VecT* start_pos, const VecT* size,SpaceT * origin);
    coord_t getTotalCoord(id_t id, size_t dim) const;
    coord_t getTotalLength(id_t id) const;
    coord_t getSelfLength(id_t id) const;
    size_t getSize() const;
    bool getSubSpace(const VecT* start_pos, const VecT* size, 
                     SpaceT **subspace);
    bool isDerived() const{return !_Origin;}
private:
    VecT max;
    size_t *_SelfMax;
    size_t *__idProjector;
    VecT _StartPos;
    SpaceT *_Origin;
    size_t *_SelfidProjector;
};
}   // namespace htm07

#endif   /* ----- #ifndef _HTM07_SPACE_H__INC  ----- */
