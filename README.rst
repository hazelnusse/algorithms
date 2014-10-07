About
=====
This is me working through the book Introduction to Algorithms, Third Edition,
by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford
Stein.

Most exercises are completed are written up in restructured text files located
in the sub-directories for each chapter.  In cases where a richer environment is
useful, I use the IPython notebook (i.e., graphs or tables or non-trivial
equations).

My goal is to implement and test everything as I go through the book, including
the exercises which ask for psuedo-code.  I have chosen C++11 as my
implementation language.

Compiling and running tests
===========================
I use CMake and Googletest.  Here are the clone and build steps::

    $ git clone https://github.com/hazelnusse/algorithms.git
    $ cd algorithms
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ make test

