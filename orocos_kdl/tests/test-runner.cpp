// Copyright (C) 2007 Klaas Gadeyne

/* Modified from orocos cppunit test code
    begin                : Mon January 10 2005
    copyright            : (C) 2005 Peter Soetens
    email                : peter.soetens@mech.kuleuven.ac.be
*/

#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    // Get the top level suite from the registry
    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    // Adds the test to the list of test to run
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( suite );
#ifndef TESTNAME
    std::ofstream outputFile(std::string(suite->getName()+"-result.xml").c_str());
#else
    std::ofstream outputFile((std::string(TESTNAME)+std::string("-result.xml")).c_str());
#endif
    // Change the default outputter to a compiler error format outputter
    runner.setOutputter( new CppUnit::XmlOutputter( &runner.result(),outputFile ) );
    
    // Run the tests.
    bool wasSucessful = runner.run();

    outputFile.close();
    // Return error code 1 if the one of test failed.
    return wasSucessful ? 0 : 1;
}
