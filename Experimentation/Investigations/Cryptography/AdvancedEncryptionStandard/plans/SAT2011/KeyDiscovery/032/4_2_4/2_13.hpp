// Matthew Gwynne, 18.2.2011 (Swansea)
/* Copyright 2011 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Investigations/Cryptography/AdvancedEncryptionStandard/plans/SAT2011/KeyDiscovery/032/4_2_4/2_13.hpp
  \brief Investigations into small scale AES key discovery for 2 + 1/3 round AES with a 4x2 plaintext matrix and 4-bit field elements


  \todo Problem specification
  <ul>
   <li> In this file, we collect the investigations into translations of
   2 + 1/3 round small scale AES with 4 rows, 2 columns, using the 4-bit
   field size. </li>
   <li> In this file, we denote this AES instance by aes(2,4,2,4). </li>
   <li> The AES encryption scheme we model takes a 32-bit plaintext and
   32-bit key and outputs a 32-bit ciphertext. The plaintext, key and
   ciphertext are all considered, column by column, as 4x2 matrices of 4-bit
   elements. </li>
   <li> In other words, in the AES blocks (plaintext, key, ciphertext etc),
   the 4-bit element at position (i,j) in the matrix is the ((i-1)*4 + j)-th
   4-bit word of the 32-bits. </li>
   <li> The 4-bit element (b_0,b_1,b_2,b_3) is considered as the polynomial
   b_0 * x^3 + b_1 * x^2 + b_2 * x + b_3. Addition and multiplication
   on these polynomials is defined as usual, modulo the polynomial x^4+x+1.
   </li>
   <li> The encryption scheme applies the following operations:
   <ol>
    <li> Addition of round key 0 (input key) to plaintext. </li>
    <li> Application of SubBytes (Sbox to each 4-bit element) operation. </li>
    <li> Application of linear diffusion operation. </li>
    <li> Addition of round key 1, resulting in the ciphertext. </li>
    <li> Application of SubBytes (Sbox to each 4-bit element) operation. </li>
    <li> Application of linear diffusion operation. </li>
    <li> Addition of round key 2, resulting in the ciphertext. </li>
   </ol>
   </li>
   <li> The Sbox is non-linear permutation over the set of 4-bit elements,
   defined as inversion within the 4-bit field composed with an affine
   transformation. </li>
   <li> The linear diffusion operation applies a linear permutation to
   the input matrix, consisting of:
   <ol>
    <li> A shift of row i by i-1 to the left for all i from 1 to the number of
    rows. </li>
    <li> The AES MixColumns operation, which takes the input matrix and
    applies a matrix multiplication by the constant matrix
    \verbatim
maxima> ss_mixcolumns_matrix(2,4,4);
 matrix([x,x+1,1,1],[1,x,x+1,1],[1,1,x,x+1],[x+1,1,1,x])
    \endverbatim
    over the 4-bit field. As it is a matrix multiplication, this operation can
    be broken down into a "MixColumn" operation on each column of the input
    matrix. </li>
   </ol>
   </li>
   <li> For a full list of the possible translations, see
   "Investigating dimensions" in
   Investigations/Cryptography/AdvancedEncryptionStandard/plans/SAT2011/Experimentation.hpp.
   </li>
  </ul>


  \todo Using the canonical box translation
  <ul>
   <li> Translation of aes(2,4,2,4):
    <ul>
     <li> We treat S-boxes, field multiplications and additions as boxes.
     </li>
     <li> S-boxes and field multiplications are translated using the canonical
     translation; see dualts_fcl in
     ComputerAlgebra/Satisfiability/Lisp/FiniteFunctions/TseitinTranslation.mac.
     </li>
     <li> Additions are translated using their prime implicates. </li>
     <li> The MixColumns operation is translated by translating both
     the MixColumns operation and it's inverse. </li>
    </ul>
   </li>
   <li> Generating small scale AES for 2 + 1/3 round:
   \verbatim
num_rounds : 2$
num_rows : 4$
num_columns : 2$
exp : 4$
final_round_b : false$
box_tran : aes_ts_box$
seed : 1$
mc_tran : aes_mc_bidirectional$
output_ss_fcl_std(num_rounds, num_columns, num_rows, exp, final_round_b, box_tran, mc_tran)$

shell> cat ssaes_r2_c2_rw4_e4_f0.cnf | ExtendedDimacsFullStatistics-O3-DNDEBUG n
 n non_taut_c red_l taut_c orig_l comment_count finished_bool
2696 20128 62248 0 62248 2697 1
 length count
1 8
2 15360
3 608
4 64
5 2048
9 1920
16 120
   \endverbatim
   </li>
   <li> In this translation, we have:
    <ul>
     <li> Two full rounds (Key Addition, SubBytes, and MixColumns operation).
     </li>
     <li> 24 S-boxes:
      <ul>
       <li> 16 from SubBytes = 8 byte * 2 rounds; </li>
       <li> 8 from key schedule = 4 row * 1 word * 2 rounds. </li>
      </ul>
     </li>
     <li> 16 multiplications by 02 = 4 rows * 1 multiplication * 2 columns *
     2 round * 1 direction (forward). </li>
     <li> 16 multiplications by 03 = 4 rows * 1 multiplication * 2 columns *
     2 round * 1 directions (forward). </li>
     <li> 16 multiplications by 09 = 4 rows * 1 multiplication * 2 columns *
     2 round * 1 directions (inverse). </li>
     <li> 16 multiplications by 11 = 4 rows * 1 multiplication * 2 columns *
     2 round * 1 directions (inverse). </li>
     <li> 16 multiplications by 13 = 4 rows * 1 multiplication * 2 columns *
     2 round * 1 directions (inverse). </li>
     <li> 16 multiplications by 14 = 4 rows * 1 multiplication * 2 columns *
     2 round * 1 directions (inverse). </li>
     <li> 288 additions:
      <ul>
       <li> 152 additions of arity 2:
        <ul>
         <li> 64 from key additions = 32 bits * 2 round; </li>
         <li> 32 from final key addition = 32 bits; </li>
         <li> 56 from the key schedule = (32 bits - 4 bits) * 2 round. </li>
        </ul>
       </li>
       <li> 8 additions of arity 3:
        <ul>
         <li> 8 from the key schedule = 4 bits * 2 rounds. </li>
        </ul>
       </li>
       <li> 128 additions of arity 4:
        <ul>
         <li> 64 from forward MixColumns = 4 rows * 2 column * 4 bits *
         2 rounds; </li>
         <li> 64 from inverse MixColumns = 4 rows * 2 column * 4 bits * 2
         rounds. </li>
        </ul>
       </li>
      </ul>
     </li>
     <li> 8 bits for the constant in the key schedule = 4 bits * 2 rounds.
     </li>
    </ul>
   </li>
   <li> The number of clauses of each length in the canonical translation:
   \verbatim
maxima> ncl_list_full_dualts(8,16);
[[2,128],[9,16],[16,1]]
   \endverbatim
   </li>
   <li> This instance has 120 boxes = 24 S-boxes + 96 multiplications.
   </li>
   <li> This instance has the following number of clauses of length:
    <ul>
     <li> 1 : 8 = key schedule constant * 1; </li>
     <li> 2 : 15360 = 120 boxes * 128; </li>
     <li> 3 : 608 = 152 additions (arity 2) * 4; </li>
     <li> 4 : 64 = 8 additions (arity 3) * 8; </li>
     <li> 5 : 2048 = 128 additions (arity 4) * 16; </li>
     <li> 9 : 1920 = 120 boxes * 16; </li>
     <li> 16 : 120 = 120 boxes * 1. </li>
    </ul>
   </li>
   <li> Then we can generate a random assignment with the plaintext and
   ciphertext, leaving the key unknown:
   \verbatim
maxima> output_ss_random_pc_pair(seed,num_rounds,num_columns,num_rows,exp,final_round_b);
   \endverbatim
   and the merging the assignment with the translation:
   \verbatim
shell> AppendDimacs-O3-DNDEBUG ssaes_r2_c2_rw4_e4_f0.cnf ssaes_pkpair_r2_c2_rw4_e4_f0_s1.cnf > r2_keyfind.cnf
   \endverbatim
   </li>
   <li> minisat-2.2.0 solves it in just over 45 minutes:
   \verbatim
shell> minisat-2.2.0 r2_keyfind.cnf
<snip>
restarts              : 32761
conflicts             : 21348407       (7855 /sec)
decisions             : 23781237       (0.00 % random) (8751 /sec)
propagations          : 9574903606     (3523177 /sec)
CPU time              : 2717.69 s
   \endverbatim
   </li>
  </ul>

*/
