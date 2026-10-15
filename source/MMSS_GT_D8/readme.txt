=====================================================================
  MMSS GRAPH THEORY REPORT TEMPLATE : HOW TO USE
=====================================================================

FILES
---------------------------------------------------------------------
  main.tex         The report itself: names, roles, problems, proofs.
                   EDIT THIS ONE, every day.

  backend.tex      Packages, page style, theorem style, all graph
                   macros. Edit only when adding a new macro.

  README.txt       This file.

  assets/logo.png  Header logo, top right. Optional.
  assets/yoda.png  ??????????????(I WONDER WHAT THAT IS....)
main.tex holds \documentclass, then a small SETTINGS block, then
\input{backend}. Everything else was moved out of it.


OVERLEAF SETUP, ONE TIME ONLY
---------------------------------------------------------------------
  1. Upload all files at the project root, not in a subfolder.

  2. Menu -> Main document -> set it to main.tex.
     Overleaf sometimes guesses wrong when two .tex files exist. If
     you get no output or a blank PDF, this is almost always why.

  3. backend.tex will show a red squiggle if you open it alone. That
     is normal. It is a fragment, not a compilable document. Ignore.

  4. The logo is optional. If assets/logo.png does not exist the
     header just stays empty instead of throwing an error.


DAILY WORKFLOW
---------------------------------------------------------------------
Open main.tex. Edit the SETTINGS block at the top:

    \newcommand{\teamname}{DJ BAAAA}
    \newcommand{\reportdate}{July 28, 2026}
    \newcommand{\logopath}{assets/logo.png}

Then fill in the frontmatter (Clarifier, Manager, Reporter, Skeptic,
Report), then write problems inside the enumerate. One problem looks
like this:

    \item Prove or disprove: $\Cn{7}$ is Eulerian.
    \begin{solution}
      Proved.
    \end{solution}
    \begin{proof}
    Every vertex of a cycle has degree 2, which is even, and the
    graph is connected, so an Eulerian circuit exists.
    \begin{graphfig}{I}
      \gcyclen{7}{1.6}{c}
    \end{graphfig}
    \end{proof}

solution prints the one word verdict. proof prints the argument and
ends with the QED box. Figures go inside whichever of the two they
belong to.


GRAPH TOOLKIT
---------------------------------------------------------------------
Every macro below must sit inside a graphfig or a tikzpicture.

  \gcycle{n}{radius}{prefix}        cycle on n vertices
  \gcyclen{n}{radius}{prefix}       same, vertices labelled 1..n
  \gcomplete{n}{radius}{prefix}     complete graph K_n
  \gbipartite{m}{n}{gap}            complete bipartite K_{m,n}
  \gpath{n}{spacing}{prefix}        path on n vertices, left to right
  \gpetersen                        Petersen graph
  \gcube{n}                         n x n x n grid cube, oblique
  \gpancake{n}{radius}              pancake graph P_n


NODE HANDLES
---------------------------------------------------------------------
The third argument is a name prefix, so \gcycle{5}{2}{c} creates
nodes c1 through c5 and you can keep drawing on them afterwards:

    \begin{graphfig}{II}
      \gcycle{5}{2}{c}
      \draw[edge,densely dashed] (c1)--(c3);   % add a chord
      \node[hv] at (c4){};                     % highlight a vertex
    \end{graphfig}

Fixed handle names:

  \gbipartite   bl1..blm on the left, br1..brn on the right
  \gpetersen    po0..po4 outside, pin0..pin4 inside
  \gpancake{n}  one node per permutation, named p plus the
                permutation, so p1234, p2134, and so on


VERTEX AND EDGE STYLES
---------------------------------------------------------------------
  v     filled black dot, the default
  ov    open ring, marks a special vertex without ink
  hv    grey highlighted hub, good for a cut vertex
  edge  the standard line width. Combine freely: \draw[edge,dashed]


FIGURE LABELS
---------------------------------------------------------------------
  \begin{graphfig}{IV}   ...   prints [Graph IV]
  \begin{graphfig}{NUM}  ...   prints [Graph 1], then 2, then 3
  \begin{graphfig}{}     ...   no title, no centring

Use {} when you want two graphs side by side: bare mode does not
centre or break the line, so consecutive bare pictures sit in a row.
The optional first argument is a scale factor:

  \begin{graphfig}[0.9]{V}


INSTRUCTOR COMMENTS
---------------------------------------------------------------------
Define once, in the SETTINGS block or in the frontmatter:

    \newinstructor{FF6600}{shaw}

That creates a macro named after the second argument:

    \shaw{the k = 1 case is not covered}

It prints the name in bold in that hex colour, then the comment. One
\newinstructor per person, each with a different colour.


GOTCHAS WORTH REMEMBERING
---------------------------------------------------------------------
  * \gpancake scaling. n = 3 is 6 nodes, n = 4 is 24 nodes, n = 5 is
    120 nodes and roughly 300 edges. n = 5 will time out on
    Overleaf's free tier. Stick to 3 and 4.

  * Do not put a tabular around a tikzpicture to lay figures out in
    a grid. The \\ scanner in tabular fights TikZ tokens. Use \lrbox
    and \usebox with \parbox, or just put bare graphfig pictures in
    a row.

  * Double \message output in the log during a TikZ picture is
    harmless. TikZ processes each picture twice, once to size it and
    once to draw it.

  * Spelling. The original macro was \gpeterson. The graph is the
    PETERSEN graph, after Julius Petersen, so the macro is now
    \gpetersen. \gpeterson still works as an alias, so old files
    keep compiling, but use the correct one going forward.

  * \pi inside a Petersen picture. The old version used \pi as its
    loop variable, which clobbered the maths symbol inside that
    picture. The loop variable is now \gp, so $\pi$ is safe.

  * New macro, new home. If you write a macro you will reuse, put it
    in backend.tex. If it is a one-off drawing for today's problem,
    leave it inline in main.tex.


VERIFIED
---------------------------------------------------------------------
The split compiles clean with pdflatex, 3 pages, no logo file
present, no errors and no warnings beyond the usual font info.