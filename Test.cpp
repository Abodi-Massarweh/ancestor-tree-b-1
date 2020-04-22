/**
 * AUTHORS: Mohamad assi,  Abodi Massarweh, Oday mahamid, 
 * Date: 2020-04
 */

#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>
using namespace std;





TEST_CASE("test 'me' case 1" ) {
	      family::Tree T ("meme");
	      
	    CHECK(T.relation("meme") == string("me"));
	   	CHECK(T.find("me") == string("meme"));
	   	CHECK_THROWS(T.find("uncle"));
}

TEST_CASE("test 'mother > mother' case 2" ) {
 
    family::Tree T ("me");
	 T.addMother("me", "mother1");
	 T.addMother("mother1", "mother2");
	 T.addMother("mother2", "mother3");
	 T.addMother("mother3", "mother4");
	 T.remove("mother3");
	 
	 
	  CHECK(T.relation("mother1") == string("mother"));
	  CHECK(T.relation("mother2") == string("grandmother"));
    CHECK(T.relation("mother3") == string("unrelated"));
    CHECK(T.relation("mother4") == string("unrelated"));
    CHECK(T.relation("mother7") == string("unrelated"));
    CHECK(T.find("mother") == string("mother1"));
    CHECK(T.find("grandmother") == string("mother2"));
    CHECK_THROWS(T.find("great-grandmother"));
    CHECK_THROWS(T.find("great-great-grandmother"));
    
    /////////////////////////////////////////////////
	 T.addMother("mother2", "mother3");
	 T.addMother("mother3", "mother4");
	 //////////////////////////////////////////////////

	 CHECK_THROWS(T.addMother("me", "mother2"));
	 CHECK_THROWS(T.addMother("me", "mother7"));
	 CHECK_THROWS(T.addMother("mother1", "mother3"));
	 CHECK_THROWS(T.addMother("mother1", "mother7"));
	 CHECK_THROWS(T.addMother("mother2", "mother1"));
	// CHECK_THROWS(T.addMother("mother1", "me"));
	// CHECK_THROWS(T.addMother("mother4", "me"));
	 
	 
    CHECK(T.relation("mother1") == string("mother"));
    CHECK(T.relation("mother2") == string("grandmother"));
    CHECK(T.relation("mother3") == string("great-grandmother"));
    CHECK(T.relation("mother4") == string("great-great-grandmother"));
    CHECK(T.relation("mother7") == string("unrelated"));
    
    CHECK(T.find("mother") == string("mother1"));
    CHECK(T.find("grandmother") == string("mother2"));
    CHECK(T.find("great-grandmother") == string("mother3"));
    CHECK(T.find("great-great-grandmother") == string("mother4"));
    CHECK_THROWS(T.find("uncle"));
    
 
}


TEST_CASE("test 'father > father' case 3" ) {
 
    family::Tree T ("me");
	 T.addFather("me", "father1");
	 T.addFather("father1", "father2");
 	 T.addFather("father2", "father3");
	 T.addFather("father3", "father4");
	 T.remove("father3");
	 
	 
	  CHECK(T.relation("father1") == string("father"));
	  CHECK(T.relation("father2") == string("grandfather"));
    CHECK(T.relation("father3") == string("unrelated"));
    CHECK(T.relation("father4") == string("unrelated"));
    CHECK(T.relation("father7") == string("unrelated"));
    CHECK(T.find("father") == string("father1"));
    CHECK(T.find("grandfather") == string("father2"));
    CHECK_THROWS(T.find("great-grandfather"));
    CHECK_THROWS(T.find("great-great-grandfather"));
    
    /////////////////////////////////////////////////
	 T.addFather("father2", "father3");
	 T.addFather("father3", "father4");
	 //////////////////////////////////////////////////
	 
	 
	 CHECK_THROWS(T.addFather("me", "father2"));
	 CHECK_THROWS(T.addFather("me", "father7"));
	 CHECK_THROWS(T.addFather("father1", "father3"));
	 CHECK_THROWS(T.addFather("father1", "father7"));
	 CHECK_THROWS(T.addFather("father2", "father1"));
	 //CHECK_THROWS(T.addFather("father1", "me"));
	 //CHECK_THROWS(T.addFather("father4", "me"));
	 
	 
    CHECK(T.relation("father1") == string("father"));
    CHECK(T.relation("father2") == string("grandfather"));
    CHECK(T.relation("father3") == string("great-grandfather"));
    CHECK(T.relation("father4") == string("great-great-grandfather"));
    CHECK(T.relation("father7") == string("unrelated"));
    
    CHECK(T.find("father") == string("father1"));
    CHECK(T.find("grandfather") == string("father2"));
    CHECK(T.find("great-grandfather") == string("father3"));
    CHECK(T.find("great-great-grandfather") == string("father4"));
    CHECK_THROWS(T.find("uncle"));
    
 
}


TEST_CASE("test 'mother > father' case 3" ) {

    family::Tree T ("me");
	 T.addMother("me", "mother1");
	 T.addFather("mother1", "father1");
	 T.addMother("father1", "mother2");///
	 T.addFather("mother2", "father2");
	 T.remove("mother2");
	 
	  /// me > mother1 > father1 > || mother2 > father2
	 
	  CHECK(T.relation("mother1") == string("mother"));
	  CHECK(T.relation("father1") == string("grandfather"));
    CHECK(T.relation("mother2") == string("unrelated"));
    CHECK(T.relation("father2") == string("unrelated"));
    CHECK(T.relation("mother7") == string("unrelated"));
    CHECK(T.find("mother") == string("mother1"));
    CHECK(T.find("grandfather") == string("father1"));
    CHECK_THROWS(T.find("great-grandmother"));
    CHECK_THROWS(T.find("great-great-grandfather"));
    
    /////////////////////////////////////////////////
	 T.addMother("father1", "mother2");
	 T.addFather("mother2", "father2");
	 //////////////////////////////////////////////////
	 
	//  me > mother1 > father1 > mother2 > father2
	 
	 CHECK_THROWS(T.addMother("me", "mother2"));
	 CHECK_THROWS(T.addMother("me", "mother7"));
	 CHECK_THROWS(T.addFather("mother1", "father3"));
	 //CHECK_THROWS(T.addMother("mother1", "mother7"));
	 CHECK_THROWS(T.addMother("father1", "mother1"));
	 //CHECK_THROWS(T.addMother("mother1", "me"));
	 //CHECK_THROWS(T.addMother("father2", "me"));
	 
	 
    CHECK(T.relation("mother1") == string("mother"));
    CHECK(T.relation("father1") == string("grandfather"));
    CHECK(T.relation("mother2") == string("great-grandmother"));
    CHECK(T.relation("father2") == string("great-great-grandfather"));
    CHECK(T.relation("mother7") == string("unrelated"));
    
    CHECK(T.find("mother") == string("mother1"));
    CHECK(T.find("grandfather") == string("father1"));
    CHECK(T.find("great-grandmother") == string("mother2"));
    CHECK(T.find("great-great-grandfather") == string("father2"));
    CHECK_THROWS(T.find("uncle"));
    
 
}

TEST_CASE("test 'father > father' case 3" ) {
 
    family::Tree T ("me");
	 T.addFather("me", "father1");
	 T.addFather("father1", "father2");
	 T.addFather("father2", "father3");
	 T.addFather("father3", "father4");
	 T.remove("father3");
	 
	 
	  CHECK(T.relation("father1") == string("father"));
	  CHECK(T.relation("father2") == string("grandfather"));
    CHECK(T.relation("father3") == string("unrelated"));
    CHECK(T.relation("father4") == string("unrelated"));
    CHECK(T.relation("father7") == string("unrelated"));
    CHECK(T.find("father") == string("father1"));
    CHECK(T.find("grandfather") == string("father2"));
    CHECK_THROWS(T.find("great-grandfather"));
    CHECK_THROWS(T.find("great-great-grandfather"));
    
    /////////////////////////////////////////////////
	 T.addFather("father2", "father3");
	 T.addFather("father3", "father4");
	 //////////////////////////////////////////////////
	 
	 
	 CHECK_THROWS(T.addFather("me", "father2"));
	 CHECK_THROWS(T.addFather("me", "father7"));
	 CHECK_THROWS(T.addFather("father1", "father3"));
	 CHECK_THROWS(T.addFather("father1", "father7"));
	 CHECK_THROWS(T.addFather("father2", "father1"));
	 CHECK_THROWS(T.addFather("father1", "me"));
	 //CHECK_THROWS(T.addFather("father4", "me"));
	 
	 
    CHECK(T.relation("father1") == string("father"));
    CHECK(T.relation("father2") == string("grandfather"));
    CHECK(T.relation("father3") == string("great-grandfather"));
    CHECK(T.relation("father4") == string("great-great-grandfather"));
    CHECK(T.relation("father7") == string("unrelated"));
    
    CHECK(T.find("father") == string("father1"));
    CHECK(T.find("grandfather") == string("father2"));
    CHECK(T.find("great-grandfather") == string("father3"));
    CHECK(T.find("great-great-grandfather") == string("father4"));
    CHECK_THROWS(T.find("uncle"));
    
 
}


TEST_CASE("test 'father > mother' case 4" ) {

    family::Tree T ("me");
	 T.addMother("me", "father1");
	 T.addFather("father1", "mother1");
	 T.addMother("mother1", "father2");///
	 T.addFather("father2", "mother2");
	 T.remove("father2");
	 
	  /// me > father1 > mother1 > || father2 > mother2
	 
	  CHECK(T.relation("father1") == string("mother"));
	  CHECK(T.relation("mother1") == string("grandfather"));
    CHECK(T.relation("father2") == string("unrelated"));
    CHECK(T.relation("mother2") == string("unrelated"));
    CHECK(T.relation("father7") == string("unrelated"));
    CHECK_THROWS(T.find("father"));
    CHECK_THROWS(T.find("great-grandmother"));
    CHECK(T.relation("father2")==string("unrelated"));
    CHECK_THROWS(T.find("great-grandfather"));
    CHECK_THROWS(T.find("great-great-grandmother"));
    
    /////////////////////////////////////////////////
	 T.addMother("mother1", "father2");
	 T.addFather("father2", "mother2");
	 //////////////////////////////////////////////////
	 
	//  me > father1 > mother1 > father2 > mother2
	 
	 CHECK_THROWS(T.addMother("me", "father2"));
	 CHECK_THROWS(T.addMother("me", "father7"));
	 CHECK_THROWS(T.addFather("father1", "assi"));
	 CHECK_THROWS(T.addFather("father1", "5ra"));
	 CHECK_THROWS(T.addMother("mother1", "father1"));
	 //CHECK_THROWS(T.addMother("father1", "me"));
	// CHECK_THROWS(T.addMother("mother2", "me"));
	 
	 
    CHECK(T.relation("father1") == string("mother"));
    CHECK(T.relation("mother1") == string("grandfather"));
    CHECK(T.relation("father2") == string("great-grandmother"));
    CHECK(T.relation("mother2") == string("great-great-grandfather"));
    CHECK(T.relation("father7") == string("unrelated"));
    
    CHECK(T.find("mother") == string("father1"));
    CHECK(T.find("grandfather") == string("mother1"));
    CHECK(T.find("great-grandmother") == string("father2"));
    CHECK(T.find("great-great-grandfather") == string("mother2"));
    CHECK_THROWS(T.find("uncle"));
    
 
}
