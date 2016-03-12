/*
 * BridJ - Dynamic and blazing-fast native interop for Java.
 * http://bridj.googlecode.com/
 *
 * Copyright (c) 2010-2015, Olivier Chafik (http://ochafik.com/)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Olivier Chafik nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY OLIVIER CHAFIK AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "stdafx.h"
#include "test.h"
#include "jni.h"
#include "math.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdarg.h>

using namespace std;

struct S_int {
	int a;	
};

struct S_int2 {
	int a, b;	
};

struct S_jlong4 {
	jlong a, b, c, d;	
};

struct S_jlong10 {
	jlong a[10];	
};

struct S_bare_interval {
	double inf, sup;
};

struct S_decorated_interval {
	double inf, sup;
        char dec;
};

TEST_API jint incr(S_int s) {
	return s.a + 1;
}
TEST_API jint sum(S_int2 s) {
	return s.a + s.b;
}
TEST_API jlong sum(S_jlong4 s) {
	return s.a + s.b + s.c + s.d;
}
TEST_API jlong sum(S_jlong10 s) {
	jlong tot = 0;
	for (int i = 0; i < 10; i++)
		tot += s.a[i];
	return tot;
}
TEST_API double sup_b(struct S_bare_interval x) {
    return x.sup;
}
TEST_API double sup_d(struct S_decorated_interval x) {
    return x.sup;
}
TEST_API struct S_bare_interval neg_b(struct S_bare_interval x) {
    struct S_bare_interval ret;
    ret.inf = -x.sup;
    ret.sup = -x.inf;
    return ret;
}
TEST_API struct S_decorated_interval neg_d(struct S_decorated_interval x) {
    struct S_decorated_interval ret;
    ret.inf = -x.sup;
    ret.sup = -x.inf;
    ret.dec = x.dec;
    return ret;
}

