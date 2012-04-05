/*
 * =====================================================================================
 *
 *       Filename:  SpatialPooler.h
 *
 *    Description:  
 *
 * =====================================================================================
 */

#ifndef  _HTM07_SPATIAL_POOLER_H__INC
#define  _HTM07_SPATIAL_POOLER_H__INC
#include "common.h"
#include <vector>
#include <cassert>

namespace htm07 {


typedef std::vector <int> OneDint_T;



class SpPatternListT
{
public:
    std::vector <data_t*> _Patterns;
    size_t size();
    size_t _Size;
    size_t _PatternSize;
    size_t getPatternSize();
    data_t* getPattern(int i);
    void push(data_t * input);
};

class SpatialPoolerT
{
public:
    SpatialPoolerT(NodeT *node)    {}
    ~SpatialPoolerT()   {}
    
    void spLearn(const data_t *input_data,size_t data_size);//main process
    const data_t * spInference(const data_t *input_data,size_t data_size); 
    bool learned() const;
    int preInputID;
    data_t _MaxDist;
    SpPatternListT* _PatternList();
    size_t patternSize() const;

    void addTimeLine(int prevID,int currID);
    std::vector <OneDint_T> _TemporalTable;
};

}   // namespace htm07

#endif   /* ----- #ifndef _HTM07_SPATIAL_POOLER_H__INC  ----- */
