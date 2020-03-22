/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p,f and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "hafby") == string("happy"));
    CHECK(find(text, "habfy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HaPpi") == string("Happi"));
    CHECK(find(text, "HapPI") == string("Happi"));
    CHECK(find(text, "HaPPI") == string("Happi"));
    CHECK(find(text, "HaPPi") == string("Happi"));
    CHECK(find(text, "happI") == string("Happi"));
    CHECK(find(text, "hAppI") == string("Happi"));
}

TEST_CASE("Test replacement of g,j ( + upper/lower case checks)") {
    string text = "XXX yyy jogging";
    CHECK(find(text, "jogging") == string("jogging"));
    CHECK(find(text, "Jogging") == string("jogging"));
    CHECK(find(text, "jojging") == string("jogging"));
    CHECK(find(text, "jojjing") == string("jogging"));
    CHECK(find(text, "jogjing") == string("jogging"));
    CHECK(find(text, "jogginj") == string("jogging"));
    CHECK(find(text, "Gojginj") == string("jogging"));
    CHECK(find(text, "joJJing") == string("jogging"));
    CHECK(find(text, "gogjing") == string("jogging"));
    CHECK(find(text, "gogginJ") == string("jogging"));
}

TEST_CASE("Test replacement of c,k,q ( + upper/lower case checks)") {
    string text = "xxx quacking yyy";
    CHECK(find(text, "quacking") == string("quacking"));
    CHECK(find(text, "Quacking") == string("quacking"));
    CHECK(find(text, "quaqqing") == string("quacking"));
    CHECK(find(text, "Quakcing") == string("quacking"));
    CHECK(find(text, "Kuakking") == string("quacking"));
    CHECK(find(text, "cuaqking") == string("quacking"));
    CHECK(find(text, "Cuaqqing") == string("quacking"));
    CHECK(find(text, "kuaqqing") == string("quacking"));
    CHECK(find(text, "KuaQCing") == string("quacking"));
    CHECK(find(text, "QuaKKing") == string("quacking"));
}

TEST_CASE("Test replacement of s,z ( + upper/lower case checks)") {
    string text = "sizzling xxx yyy";
    CHECK(find(text, "sizzling") == string("sizzling"));
    CHECK(find(text, "Sizzling") == string("sizzling"));
    CHECK(find(text, "SiSSling") == string("sizzling"));
    CHECK(find(text, "siszling") == string("sizzling"));
    CHECK(find(text, "Zizzling") == string("sizzling"));
    CHECK(find(text, "ZizSling") == string("sizzling"));
    CHECK(find(text, "SiSZling") == string("sizzling"));
    CHECK(find(text, "sissling") == string("sizzling"));
    CHECK(find(text, "ziszling") == string("sizzling"));
    CHECK(find(text, "zizzling") == string("sizzling"));
}

TEST_CASE("Test replacement of d,t ( + upper/lower case checks)") {
    string text = "Book of Deuteronomy";
    CHECK(find(text, "deuteronomy") == string("Deuteronomy"));
    CHECK(find(text, "Deuteronomy") == string("Deuteronomy"));
    CHECK(find(text, "Teuteronomy") == string("Deuteronomy"));
    CHECK(find(text, "Teuderonomy") == string("Deuteronomy"));
    CHECK(find(text, "Deuderonomy") == string("Deuteronomy"));
    CHECK(find(text, "deuDeronomy") == string("Deuteronomy"));
    CHECK(find(text, "deuTeronomy") == string("Deuteronomy"));
    CHECK(find(text, "TeuTeronomy") == string("Deuteronomy"));
    CHECK(find(text, "DeuDeronomy") == string("Deuteronomy"));
    CHECK(find(text, "teuderonomy") == string("Deuteronomy"));
}

TEST_CASE("Test replacement of o, u ( + upper/lower case checks)") {
    string text = "opportunity xxx yyy";
    CHECK(find(text, "opportunity") == string("opportunity"));
    CHECK(find(text, "Opportunity") == string("opportunity"));
    CHECK(find(text, "Upportunity") == string("opportunity"));
    CHECK(find(text, "uppurtonity") == string("opportunity"));
    CHECK(find(text, "uppurtunity") == string("opportunity"));
    CHECK(find(text, "opportonity") == string("opportunity"));
    CHECK(find(text, "OppUrtOnity") == string("opportunity"));
    CHECK(find(text, "uppUrtOnity") == string("opportunity"));
    CHECK(find(text, "Oppurtunity") == string("opportunity"));
    CHECK(find(text, "oppurtonity") == string("opportunity"));
}

TEST_CASE("Test replacement of i,y ( + upper/lower case checks)") {
    string text = "xxx yyy Yerushalayim";
    CHECK(find(text, "Yerushalayim") == string("Yerushalayim"));
    CHECK(find(text, "yerushalayim") == string("Yerushalayim"));
    CHECK(find(text, "Ierushalayim") == string("Yerushalayim"));
    CHECK(find(text, "ierushalaiim") == string("Yerushalayim"));
    CHECK(find(text, "Yerushalayym") == string("Yerushalayim"));
    CHECK(find(text, "yerushalaiym") == string("Yerushalayim"));
    CHECK(find(text, "YerushalaYYm") == string("Yerushalayim"));
    CHECK(find(text, "ierushalaYim") == string("Yerushalayim"));
    CHECK(find(text, "yerushalaYIm") == string("Yerushalayim"));
    CHECK(find(text, "ierushalayym") == string("Yerushalayim"));
}

TEST_CASE("Test replacement of multiple cases in a single word") {
    string text("convolutional neural network");
    CHECK(find(text, "convolutional") == string("convolutional"));
    CHECK(find(text, "Qunwolutyunal") == string("convolutional"));
    CHECK(find(text, "KonwUlodYUnal") == string("convolutional"));
    CHECK(find(text, "CUNWULOTYONAL") == string("convolutional"));
    CHECK(find(text, "qonwolotiunal") == string("convolutional"));

    CHECK(find(text, "NETWORQ") == string("network"));
    CHECK(find(text, "nedvUrC") == string("network"));
    CHECK(find(text, "nEtWUrQ") == string("network"));
    CHECK(find(text, "nedwurc") == string("network"));
    CHECK(find(text, "Netwurk") == string("network"));

}
/* Add more test cases here */
