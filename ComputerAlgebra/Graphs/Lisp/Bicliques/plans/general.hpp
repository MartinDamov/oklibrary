// Oliver Kullmann, 16.1.2009 (Swansea)
/* Copyright 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Graphs/Lisp/Bicliques/plans/general.hpp
  \brief Plans regarding bicliques of (general) graphs


  \todo The notion of a "biclique"
  <ul>
   <li> General discussion:
    <ol>
     <li> The "full" mathematical notion of a biclique B in a (general/multi-)
     graph G is that of a sub-graph of G, which itself is a complete bipartite
     graph. </li>
     <li> Since the edges determine the sub-graph B, it is natural to represent
     B by a set B' of edges. </li>
     <li> However then we have the problem, that this notion is not stable
     under sub-set-formation, i.e., a subset of B' in general is not again
     a biclique. </li>
     <li> So for multigraphs and graphs G alternatively we can use
     sets of *vertices* B' such that we can find edges in B' making it
     a complete biclique. </li>
     <li> For graphs this is the subgraph induced by B' </li>
     <li> However, then it is needed to specify the bipartitioning, since in
     general there are many ways that a set of vertices could form a biclique.
     </li>
    </ol>
   </li>
   <li> For multigraphs a biclique partition is a "numerical condition",
   which seems perfectly appropriate since multigraphs are close to
   combinatorial matrices. </li>
   <li> Only for general graphs, where the edges have an identity, we need to
   know precisely which edges are part of the biclique. </li>
   <li> So we could speak of a "subgraph-biclique", "edge-set-biclique" and
   "vertex-set-biclique" (where the latter is a pair of vertex-sets). </li>
   <li> For the ordered graph versions instead a vertex-sets we have
   vertex-lists, and their order must conform with the given total
   order; the abbreviation then is "ovbc". </li>
   <li> DONE (since we need two subsets, it's not really a hypergraph)
   The vertex-bicliques then form a hereditary hypergraph (vertices
   the vertices of the given graph; "hereditary" means that for every
   hyperedge also every subset is a hyperedge, where here we must
   exclude subsets of size 0 or 1). </li>
   <li> DONE (solved by using pairs)
   Likely for (general) digraphs for a given vertex-biclique there are
   several possibilities to interprete it as a edge-biclique, but otherwise
   there should be no ambiguities. </li>
   <li> A subgraph-biclique as well as an edge-biclique can be refined by
   specifying an associated vertex-biclique (which fixes the bipartitioning).
   </li>
  </ul>


  \todo Abbreviations
  <ul>
   <li> "bc" for "biclique". </li>
   <li> Bicliques exist as "sbc", "ebc" and "vbc" (subgraphs, edge-sets
   or vertex-sets). </li>
   <li> A test would be named e.g. "sbc_ogdg_p". </li>
  </ul>


  \todo Directed graphs
  <ul>
   <li> Above we only considered undirected graphs, however it seems that
   perhaps directed graphs are somewhat more fundamental here (at least
   computationally). </li>
   <li> The point is that there are no problems with the sides of the
   biclique (note that a biclique now requires all edges to go from
   one side to the other); this is especially important for clause-sets
   where literals always have a polarity. </li>
   <li> For combinatorial matrices we consider the adjacency matrices
   of directed graphs, which are nonnegative (but not symmetric). </li>
  </ul>


  \todo Maximal biclique
  <ul>
   <li> We need tests for checking whether a biclique is maximal (cannot
   be extended). </li>
   <li> For an algorithm finding all maximal bicliques see
   ComputerAlgebra/Graphs/Lisp/Bicliques/plans/Consensus.hpp. </li>
  </ul>


  \todo Maximum bicliques
  <ul>
   <li> There are two ways of measuring the size of a biclique: the number of
   edges and the number of vertices. </li>
   <li> So let's speak of "maximum-vertices bicliques" and "maximum-edges
   bicliques". </li>
   <li> The maximum-edges biclique decision problem (for a given lower bound
   on the number of edges):
    <ol>
     <li> In [Sperschneider, Bioinformatics, Springer 2008], Theorem 5.42, this
     is shown to be NP-complete, even if the graph is just bipartite. </li>
     <li> From this proof a reduction of 3-SAT to this problem can be derived;
     we should implement this. </li>
     <li> On the other hand, we should also have algorithms and reductions for
     solving this problem. </li>
     <li> If the number of edges is given as a parameter: Is this problem then
     fixed-parameter tractable? </li>
    </ol>
   </li>
   <li> The maximum-vertices biclique decision problem:
    <ol>
     <li> Is this also NP-complete? </li>
     <li> And with the number of vertices as parameter: Is this problem then
     fixed-parameter tractable? </li>
    </ol>
   </li>
   <li> See "Bioinformatics" in ComputerAlgebra/plans/general.hpp for an
   application. </li>
  </ul>

*/

