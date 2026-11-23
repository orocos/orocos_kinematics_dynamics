#ifndef KINFAM_TEST_HPP
#define KINFAM_TEST_HPP

#include <cppunit/extensions/HelperMacros.h>
#include <kdl/frames.hpp>
#include <kdl/joint.hpp>
#include <kdl/segment.hpp>
#include <kdl/chain.hpp>
#include <kdl/tree.hpp>

using namespace KDL;

class KinFamTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( KinFamTest);
    CPPUNIT_TEST( JointTest );
    CPPUNIT_TEST( SegmentTest );
    CPPUNIT_TEST( ChainTest );
    CPPUNIT_TEST( TreeTest );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void JointTest();
    void SegmentTest();
    void ChainTest();
    void TreeTest();

};

#endif
