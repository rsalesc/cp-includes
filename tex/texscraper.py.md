---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from glob import glob\nimport os\nimport fnmatch\nimport collections\n\n\
    from mako.template import Template\n\nBLOCKLIST_PATTERNS = [\n  \"bits/*\",\n\
    \  \"tests/*\",\n  \"scripts/*\",\n  \"tex/*\",\n  \"traits/*\",\n  \"utils/*\"\
    ,\n  \"pbds/*\",\n  \"matroid/v2/*\",\n  \".*\",\n  \"Lambda.cpp\",\n  \"HashMap.cpp\"\
    ,\n  \"Bitset.cpp\",\n]\n\ndef is_blocked(path):\n  return any(fnmatch.fnmatch(path,\
    \ pat) for pat in BLOCKLIST_PATTERNS)\n\ndef build_sections(code_files):\n  sections\
    \ = collections.defaultdict(lambda: collections.defaultdict(list))\n  for file\
    \ in code_files:\n    section_name = os.path.dirname(file)\n    if not section_name:\n\
    \      section_name = \"unindexed\"\n    subsection_name = os.path.splitext(os.path.basename(file))[0]\n\
    \    sections[section_name][subsection_name].append(file)\n  return {\n    k:\
    \ dict(v) for k, v in sections.items()\n  }\n\ndef render(code_files, dest_file):\n\
    \  tex_dir = os.path.dirname(os.path.abspath(__file__))\n  main_tex = os.path.join(tex_dir,\
    \ \"main.tex\")\n  mako_path = os.path.join(tex_dir, \"sections.mako\")\n\n  sections\
    \ = build_sections(code_files)\n  rendered_sections = Template(open(mako_path,\
    \ \"r\").read()).render(sections=sections)\n  \n  tex = open(main_tex, \"r\").read()\n\
    \  output = tex.replace(\"%CODE\", rendered_sections)\n  out_path = os.path.join(tex_dir,\
    \ dest_file)\n  open(out_path, \"w\").write(output)\n\ndef scrape():\n  root_dir\
    \ = os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir)\n  candidate_files\
    \ = [\n    os.path.relpath(file, root_dir) for file in glob(os.path.join(root_dir,\
    \ \"**/*.cpp\"), recursive=True)\n  ]\n  matching_files = [file for file in candidate_files\
    \ if not is_blocked(file)]\n  \n  render(matching_files, dest_file=\"result.tex\"\
    )\n\nif __name__ ==  \"__main__\":\n  scrape()"
  dependsOn: []
  isVerificationFile: false
  path: tex/texscraper.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tex/texscraper.py
layout: document
redirect_from:
- /library/tex/texscraper.py
- /library/tex/texscraper.py.html
title: tex/texscraper.py
---
