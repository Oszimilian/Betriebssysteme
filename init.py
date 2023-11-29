import os

def create_project_folder():
    # Benutzereingabe für den Ordnername
    project_name = input("Geben Sie den Namen des Ordners ein: ")

    # Erstellen des Projektordners
    project_folder = os.path.join(os.getcwd(), project_name)
    os.makedirs(project_folder, exist_ok=True)

    # Wechseln zum Projektordner
    os.chdir(project_folder)

    # Erstellen der main.c Datei
    mainc_content = f'''
#include <stdio.h>
#include <stdlib.h>

int main(void) {{
    printf("{project_name} build successfully \\n");
    return EXIT_SUCCESS;
}}
'''



    with open('main.c', 'w') as main_file:
        main_file.write(mainc_content)

    # Erstellen der CMakeLists.txt Datei
    cmake_content = f'''cmake_minimum_required(VERSION 3.10)
project({project_name})

file(GLOB HEADER_FILES "*.h")
file(GLOB SRC_FILES "*.c")

set(CMAKE_CXX_STANDARD 17)

add_executable(${{PROJECT_NAME}} ${{HEADER_FILES}} ${{SRC_FILES}})
'''

    with open('CMakeLists.txt', 'w') as cmake_file:
        cmake_file.write(cmake_content)

    # Erstellen des Build-Ordners
    build_folder = os.path.join(project_folder, 'build')
    os.makedirs(build_folder, exist_ok=True)

    print(f'Projekt wurde erstellt im Ordner: {project_folder}')

    cmake_cmd = f"cmake -S {os.getcwd()} -B {build_folder}"

    os.system(cmake_cmd)

    os.chdir(build_folder)

    os.system("make")

    os.system(f"./{project_name}")

if __name__ == "__main__":
    create_project_folder()