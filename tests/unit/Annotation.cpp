#include "../../utils/Annotation.cpp"
#include "../catch.hpp"

using namespace lib;

struct ToBeNoted {
    int x;
    ToBeNoted(char c) : x(c) {}
};

template<typename T>
struct Comparator {
  bool operator()(const T& a, const T& b) const {
    return a < b;
  }
  template <typename Iterator>
  static void sort(Iterator begin, Iterator end) {
    Comparator<T> cmp;
    std::sort(begin, end, cmp);
  }
};

TEST_CASE("note construction", "[note]") {
    SECTION("default constructor") {
        Note<std::vector<int>, int> with_note;
        Note<std::vector<int>> without_note;

        REQUIRE(annotation(with_note) == 0);
    }
    
    SECTION("custom constructor") {
        Note<ToBeNoted, int> to_be_noted_with_note('a');
        Note<ToBeNoted> to_be_noted_without_note('a');

        REQUIRE(to_be_noted_with_note.x == 'a');
        REQUIRE(annotation(to_be_noted_with_note) == 0);
    }

    SECTION("custom notes") {
        Note<ToBeNoted, int> to_be_noted_with_note = make_note<ToBeNoted, int>('a', 5);

        REQUIRE(annotation(to_be_noted_with_note) == 5);

        annotation(to_be_noted_with_note) = 10;

        REQUIRE(annotation(to_be_noted_with_note) == 10);
    }

    SECTION("note assignment") {
        Note<ToBeNoted> to_be_noted_without_note = ToBeNoted('c');
        REQUIRE(to_be_noted_without_note.x == 'c');

        to_be_noted_without_note = ToBeNoted('d');
        REQUIRE(to_be_noted_without_note.x == 'd');
    }

    SECTION("make_note") {
        auto to_be_noted_with_note = make_note(ToBeNoted('c'), 5);

        REQUIRE(is_same<decltype(to_be_noted_with_note), Note<ToBeNoted, int>>::value == true);
        REQUIRE(to_be_noted_with_note.x == 'c');
        REQUIRE(annotation(to_be_noted_with_note) == 5);
    }
}

TEST_CASE("comparator polymorphism", "[note]") {
    SECTION("operator<") {
        auto note_a = make_note<string, int>("abc", 5);
        auto note_b = make_note<string, int>("cde", 2);
        Comparator<string> cmp;
        REQUIRE(cmp(note_a, note_b) == true);
    }

    SECTION("sort") {
        vector<Note<string, int>> vs;
        auto note_a = make_note<string, int>("abc", 5);
        auto note_b = make_note<string, int>("cde", 2);
        vs.push_back(note_b);
        vs.push_back(note_a);

        Comparator<string>::sort(vs.begin(), vs.end());
        REQUIRE(vs[0] == note_a);
        REQUIRE(vs[1] == note_b);
    }
}