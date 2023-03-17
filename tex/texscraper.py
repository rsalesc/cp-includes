from glob import glob
import os
import fnmatch
import collections

from mako.template import Template

BLOCKLIST_PATTERNS = [
  "bits/*",
  "tests/*",
  "scripts/*",
  "tex/*",
  "traits/*",
  "utils/*",
  "pbds/*",
  "matroid/v2/*",
  ".*",
  "Lambda.cpp",
  "HashMap.cpp",
  "Bitset.cpp",
]

def is_blocked(path):
  return any(fnmatch.fnmatch(path, pat) for pat in BLOCKLIST_PATTERNS)

def build_sections(code_files):
  sections = collections.defaultdict(lambda: collections.defaultdict(list))
  for file in code_files:
    section_name = os.path.dirname(file)
    if not section_name:
      section_name = "unindexed"
    subsection_name = os.path.splitext(os.path.basename(file))[0]
    sections[section_name][subsection_name].append(file)
  return {
    k: dict(v) for k, v in sections.items()
  }

def render(code_files, dest_file):
  tex_dir = os.path.dirname(os.path.abspath(__file__))
  main_tex = os.path.join(tex_dir, "main.tex")
  mako_path = os.path.join(tex_dir, "sections.mako")

  sections = build_sections(code_files)
  rendered_sections = Template(open(mako_path, "r").read()).render(sections=sections)
  
  tex = open(main_tex, "r").read()
  output = tex.replace("%CODE", rendered_sections)
  out_path = os.path.join(tex_dir, dest_file)
  open(out_path, "w").write(output)

def scrape():
  root_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir)
  candidate_files = [
    os.path.relpath(file, root_dir) for file in glob(os.path.join(root_dir, "**/*.cpp"), recursive=True)
  ]
  matching_files = [file for file in candidate_files if not is_blocked(file)]
  
  render(matching_files, dest_file="result.tex")

if __name__ ==  "__main__":
  scrape()