import os
import json

def build():
    # Base directory
    base_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Paths to JSON datasets
    path_translator = os.path.join(base_dir, 'data_translator.json')
    path_patterns = os.path.join(base_dir, 'data_patterns.json')
    path_mistakes = os.path.join(base_dir, 'data_mistakes.json')
    path_practice = os.path.join(base_dir, 'data_practice.json')
    
    # Read JSON files
    with open(path_translator, 'r', encoding='utf-8') as f:
        data_translator = json.load(f)
    
    with open(path_patterns, 'r', encoding='utf-8') as f:
        data_patterns = json.load(f)
        
    with open(path_mistakes, 'r', encoding='utf-8') as f:
        data_mistakes = json.load(f)
        
    with open(path_practice, 'r', encoding='utf-8') as f:
        data_practice = json.load(f)
        
    # Path to template
    template_path = os.path.join(base_dir, 'template.html')
    if not os.path.exists(template_path):
        print(f"Error: {template_path} does not exist.")
        return
        
    with open(template_path, 'r', encoding='utf-8') as f:
        html_content = f.read()
        
    # Replace placeholders with JSON strings
    html_content = html_content.replace('/*DATA_TRANSLATOR*/', json.dumps(data_translator, indent=2))
    html_content = html_content.replace('/*DATA_PATTERNS*/', json.dumps(data_patterns, indent=2))
    html_content = html_content.replace('/*DATA_MISTAKES*/', json.dumps(data_mistakes, indent=2))
    html_content = html_content.replace('/*DATA_PRACTICE*/', json.dumps(data_practice, indent=2))
    
    # Write to target destination
    output_path = os.path.join(os.path.dirname(base_dir), 'sql-join-cheatsheet.html')
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(html_content)
        
    print(f"Successfully generated offline cheat sheet at: {output_path}")

if __name__ == '__main__':
    build()
