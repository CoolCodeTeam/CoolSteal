/**
 * Copyright (c) 2016 Philippe FERDINAND
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/
#pragma once

#include <stdexcept>

namespace db {
  namespace postgres {
    
    /**
     * Exception thrown on connection failure.
     **/
    class ConnectionException : public std::runtime_error {
    public:
      /**
       * Constructor.
       *
       * @param what - The error message returned by the server.
       **/
      ConnectionException(const std::string &what)
      : std::runtime_error(what) {
      }
    };

    /**
     * Exception thrown on any runtime error except a connection failure.
     **/
    class ExecutionException : public std::runtime_error {
    public:
      /**
       * Constructor.
       *
       * @param what - The error message returned by the server.
       **/
      ExecutionException(const std::string &what)
      : std::runtime_error(what) {
      }
    };

  } // namespace postgres
}   // namespace db
