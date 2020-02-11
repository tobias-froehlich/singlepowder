#ifndef UTILS_H_
#define UTILS_H_

namespace utils {
  std::vector< std::string > split(std::string str, char delimiter);
    // Splits str into words, seperated by delimiter. Several delimeters
    // occuring in a group are treated as one. Delimiters at beginning or end
    // are ignored.
  std::vector< std::string > split_equal(std::string str, int size);
    // Splits str into words of length size. If length of str is not
    // a multiple of size, then the last word is shorter.
  std::vector< std::vector< int > > rearrange_to_2index(
    std::vector< int > values,
    int nrows,
    int ncols
  ); // Fills the 1-index array "values" to a 2-index array.
     // The length of the 1-index array must be nrows x ncols.
     // Otherwise invalid_argument.
  std::string remove_comment(std::string line);
      // removes everything from the string from the first comment tag.
      // Which character this is, is specified in const.cpp (zCommentTag).
}

#endif
