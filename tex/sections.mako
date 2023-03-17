% for section, subsections in sections.items():
\section{${section}}{
  % for subsection, paths in sorted(subsections.items(), key=lambda x: x[0]):
  \subsection{${subsection}}{
    % for path in paths:
      \includecode{${path}}
    % endfor
  }
  % endfor
}
% endfor