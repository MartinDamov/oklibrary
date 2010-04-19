// Oliver Kullmann, 5.4.2009 (Swansea)
/* Copyright 2009, 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/GreenTaoProblems/Transversals/plans/Datak6.hpp
  \brief Investigating the transversal hypergraph of Green-Tao hypergraphs for k = 6 (length of arithmetic progressions)


  \todo Elementary statistics
  <ul>
   <li> Investigating tr_arithprog_hg(6,n). </li>
   <li> The numbers of minimum hyperedges:
   \verbatim
A6p(n):=arithprog_primes_hg(6,n)$
oklib_monitor : true$
Lp200_6 : minimum_transversals_mongen(200,A6p,[{}])$
1 0 1
2 0 1
3 0 1
4 0 1
5 0 1
6 0 1
7 0 1
8 0 1
9 0 1
10 0 1
11 0 1
12 0 1
13 0 1
14 0 1
15 0 1
16 0 1
17 0 1
18 0 1
19 0 1
20 0 1
21 0 1
22 0 1
23 0 1
24 0 1
25 0 1
26 0 1
27 0 1
28 0 1
29 0 1
30 0 1
31 0 1
32 0 1
33 0 1
34 0 1
35 0 1
36 0 1
37 1 6
38 1 6
39 1 6
40 1 6
41 1 6
42 1 6
43 1 6
44 1 6
45 1 6
46 1 6
47 1 6
48 1 6
49 1 6
50 1 6
51 1 6
52 1 6
53 1 6
54 1 6
55 2 36
56 2 36
57 2 36
58 2 36
59 2 36
60 2 36
61 2 36
62 2 36
63 2 36
64 3 216
65 3 216
66 3 216
67 3 216
68 3 216
69 3 216
70 3 216
71 4 1296
72 4 1296
73 4 1296
74 4 1296
75 4 1296
76 4 1296
77 4 1296
78 4 1296
79 4 1296
80 4 1296
81 4 1296
82 4 1296
83 4 1296
84 4 1296
85 4 1296
86 4 1296
87 4 1296
88 4 1296
89 4 1296
90 5 7776
91 5 7776
92 5 7776
93 5 7776
94 5 7776
95 5 7776
96 5 7776
97 6 46656
98 6 46656
99 6 46656
100 6 46656
101 6 46656
102 6 46656
103 6 46656
104 6 46656
105 6 46656
106 6 46656
107 6 46656
108 6 46656
109 6 46656
110 6 46656
111 6 46656
112 6 46656
113 6 46656
114 6 46656
115 6 46656
116 6 46656
117 6 46656
118 6 46656
119 6 46656
120 6 46656
121 6 46656
122 6 46656
123 6 46656
124 6 46656
125 7 279936
126 7 279936
127 7 279936
128 7 279936
129 7 279936
130 7 279936
131 7 279936
132 7 279936
133 7 279936
134 7 93312
135 7 93312
136 7 93312
137 7 93312
138 7 93312
139 7 93312
140 7 93312
141 7 93312
142 7 93312
143 7 15552
144 7 15552
145 7 15552
146 7 5184
147 7 5184
148 7 5184
149 7 5184
150 7 5184
151 7 5184
152 8 31104
153 8 31104
154 8 31104
155 8 15552
156 8 15552
157 8 15552
158 8 15552
159 8 15552
160 8 7776
161 8 7776
162 9 46656
163 9 46656
164 9 46656
165 9 46656
166 9 46656
167 9 46656
168 9 46656
169 9 46656
170 9 46656
171 9 46656
172 9 46656
173 9 46656
174 9 46656
175 9 46656
176 9 46656
177 9 46656
178 9 46656
179 10 699840
180 10 699840
181 10 699840
182 10 699840
183 10 699840
184 10 116640
185 10 116640
186 10 116640
187 10 116640
188 10 116640
189 10 116640
190 10 116640
191 10 116640
192 10 116640
193 10 116640
194 10 116640
195 10 116640
196 10 116640
197 10 116640
198 10 116640
199 10 116640
200 10 19440
   \endverbatim
   </li>
   <li> All counts have a rather simple structure when represented using
   base 6 (using int2polyadic(count,6))! One should investigate this. </li>
   <li> At C++ level:
   \verbatim
> MinimumTransversals_GreenTao-O3-DNDEBUG 300 6 | tee GreenTao_Trans_6_300_OUT
201 11 184680
202 11 184680
203 11 184680
204 12 1108080
205 12 1108080
206 12 1108080
207 12 1108080
208 12 1108080
209 12 1108080
210 12 1108080
   \endverbatim
   (the machine has only 1GB of RAM, and the computation was then aborted).
   </li>
   <li> For orientation, those n-values where at least one hyperedge has been
   added (compared to n-1):
   \verbatim
for n: 5 thru 300 do block(
 [d:nhyp_arithprog_primes_ohg(6,n)-nhyp_arithprog_primes_ohg(6,n-1)],
  if d>0 then print(n));
37
55
64
71
90
97
125
134
143
146
152
155
160
162
179
184
200
201
204
211
212
214
228
232
242
250
263
269
275
289
292
293
294
   \endverbatim
   </li>
  </ul>


  \todo Only computing the transversal numbers
  <ul>
   <li> Just computing the transversal numbers, using minisat2 and the
   direct translation (as provided by
   "GTTransversalsInc 6 1 0 OutputFile OutputSAT"):
   \verbatim
k n tau
6 1 0
6 2 0
6 3 0
6 4 0
6 5 0
6 6 0
6 7 0
6 8 0
6 9 0
6 10 0
6 11 0
6 12 0
6 13 0
6 14 0
6 15 0
6 16 0
6 17 0
6 18 0
6 19 0
6 20 0
6 21 0
6 22 0
6 23 0
6 24 0
6 25 0
6 26 0
6 27 0
6 28 0
6 29 0
6 30 0
6 31 0
6 32 0
6 33 0
6 34 0
6 35 0
6 36 0
6 37 1
6 38 1
6 39 1
6 40 1
6 41 1
6 42 1
6 43 1
6 44 1
6 45 1
6 46 1
6 47 1
6 48 1
6 49 1
6 50 1
6 51 1
6 52 1
6 53 1
6 54 1
6 55 2
6 56 2
6 57 2
6 58 2
6 59 2
6 60 2
6 61 2
6 62 2
6 63 2
6 64 3
6 65 3
6 66 3
6 67 3
6 68 3
6 69 3
6 70 3
6 71 4
6 72 4
6 73 4
6 74 4
6 75 4
6 76 4
6 77 4
6 78 4
6 79 4
6 80 4
6 81 4
6 82 4
6 83 4
6 84 4
6 85 4
6 86 4
6 87 4
6 88 4
6 89 4
6 90 5
6 91 5
6 92 5
6 93 5
6 94 5
6 95 5
6 96 5
6 97 6
6 98 6
6 99 6
6 100 6
6 101 6
6 102 6
6 103 6
6 104 6
6 105 6
6 106 6
6 107 6
6 108 6
6 109 6
6 110 6
6 111 6
6 112 6
6 113 6
6 114 6
6 115 6
6 116 6
6 117 6
6 118 6
6 119 6
6 120 6
6 121 6
6 122 6
6 123 6
6 124 6
6 125 7
6 126 7
6 127 7
6 128 7
6 129 7
6 130 7
6 131 7
6 132 7
6 133 7
6 134 7
6 135 7
6 136 7
6 137 7
6 138 7
6 139 7
6 140 7
6 141 7
6 142 7
6 143 7
6 144 7
6 145 7
6 146 7
6 147 7
6 148 7
6 149 7
6 150 7
6 151 7
6 152 8
6 153 8
6 154 8
6 155 8
6 156 8
6 157 8
6 158 8
6 159 8
6 160 8
6 161 8
6 162 9
6 163 9
6 164 9
6 165 9
6 166 9
6 167 9
6 168 9
6 169 9
6 170 9
6 171 9
6 172 9
6 173 9
6 174 9
6 175 9
6 176 9
6 177 9
6 178 9
6 179 10
6 180 10
6 181 10
6 182 10
6 183 10
6 184 10
6 185 10
6 186 10
6 187 10
6 188 10
6 189 10
6 190 10
6 191 10
6 192 10
6 193 10
6 194 10
6 195 10
6 196 10
6 197 10
6 198 10
6 199 10
6 200 10
6 201 11
6 202 11
6 203 11
6 204 12
6 205 12
6 206 12
6 207 12
6 208 12
6 209 12
6 210 12
6 211 13
6 212 14
6 213 14
6 214 14
6 215 14
6 216 14
6 217 14
6 218 14
6 219 14
6 220 14
6 221 14
6 222 14
6 223 14
6 224 14
6 225 14
6 226 14
6 227 14
6 228 14
6 229 14
6 230 14
6 231 14
6 232 14
6 233 14
6 234 14
6 235 14
6 236 14
6 237 14
6 238 14
6 239 14
6 240 14
6 241 14
6 242 14
6 243 14
6 244 14
6 245 14
6 246 14
6 247 14
6 248 14
6 249 14
6 250 15
6 251 15
6 252 15
6 253 15
6 254 15
6 255 15
6 256 15
6 257 15
6 258 15
6 259 15
6 260 15
6 261 15
6 262 15
6 263 15
6 264 15
6 265 15
6 266 15
6 267 15
6 268 15
6 269 15
6 270 15
6 271 15
6 272 15
6 273 15
6 274 15
6 275 15
6 276 15
6 277 15
6 278 15
6 279 15
6 280 15
6 281 15
6 282 15
6 283 15
6 284 15
6 285 15
6 286 15
6 287 15
6 288 15
   \endverbatim
   </li>
  </ul>

*/

