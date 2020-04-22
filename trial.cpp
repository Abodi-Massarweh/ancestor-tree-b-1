//
// Created by abodi on 22/04/2020.
//
#include "FamilyTree.hpp"
#include "doctest.h"

TEST_CASE("ALICE AND ABODI")
{
    family::Tree T ("Yosef");
    T.addFather("Yosef", "Yaakov");
    T.addMother("Yosef", "Rachel");
            CHECK_THROWS(T.addFather("Yosef", "Yaakov")); // duplicate father
            CHECK_THROWS(T.addMother("Yosef", "Rivka"));  // duplicate mother
    T.addFather("Yaakov", "Isaac");
    T.addMother("Yaakov", "Rivka");
    T.addFather("Rachel", "Avi");
    T.addMother("Rachel", "Ruti");
    T.addFather("Isaac", "Avraham");
    T.addMother("Isaac", "Ruti");
            CHECK_THROWS(T.addFather("Isaac", "Israel"));  // duplicate father
            CHECK_THROWS(T.addMother("Isaac", "Ruti"));    // duplicate mother
    T.addFather("Avraham", "Yosi");
    T.addMother("Avraham", "Shelly");
    T.addFather("Avi", "Israel");
    T.addMother("Avi", "Sara");
            CHECK_THROWS(T.addFather("Avraham", "Avraham"));    // duplicate father
            CHECK_THROWS(T.addMother("Avraham", "Sara"));       // duplicate mother






    // Remove test case
    //CHECK_THROWS(T.remove("Yosef"));  // removing the root is an error
            CHECK_THROWS(T.remove(" "));      // removing a non-existent person
            CHECK_THROWS(T.remove("xyz"));
            CHECK_THROWS(T.remove("Ariel"));
            CHECK_THROWS(T.remove("  Rivka"));

    T.remove("Yosi");  // remove the great-great-grandfather
            CHECK_THROWS(T.find("great-great-grandfather"));  // A removed relation does not exist
    T.addFather("Avraham", "Ido");  // Add a new father after removal
    T.remove("Avi");
            CHECK_THROWS(T.addFather("Avi", "Israel"));  // add to a removed person
    T.addFather("Rachel", "Shmual");
    T.remove("Isaac");
    T.remove("Rivka");
    T.remove("Ruti");
            CHECK_THROWS(T.find("grandmother"));
            CHECK_THROWS(T.addFather("Isaac", "Avraham"));
            CHECK_THROWS(T.addMother("Isaac", "Ruti"));
            CHECK_THROWS(T.addFather("Rivka", "Israel"));
            CHECK_THROWS(T.addMother("Rivka", "Sara"));
    T.remove("Yaakov");  // remove father
    T.remove("Rachel");  // remove mother
            CHECK_THROWS(T.find("father"));
           CHECK_THROWS(T.find("mother"));
            CHECK_THROWS(T.addFather("Yaakov", "Avraham"));   // add to non-existent person
            CHECK_THROWS(T.addMother("Yaakov", "Ruti"));      // add to non-existent person
            CHECK_THROWS(T.addFather("Rachel", "Avraham"));   // add to non-existent person
            CHECK_THROWS(T.addMother("Rachel", "Ruti"));      // add to non-existent person
}