configure_file("english.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

cxx_test(
   TARGET word_ladder_test1
   FILENAME word_ladder_test1.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_benchmark
   FILENAME word_ladder_test_benchmark.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_smallLexicon
   FILENAME word_ladder_test_smallLexicon.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_compareWord
   FILENAME word_ladder_test_compareWord.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_BFS
   FILENAME word_ladder_test_BFS.cpp
   LINK word_ladder lexicon test_main
)