MACRO(RECURSIVE_FIND_DIR return_list dir pattern)
    FILE(GLOB_RECURSE new_list "${dir}/${pattern}")
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

MACRO(RECURSIVE_FIND_FILE return_list dir pattern)
    FILE(GLOB_RECURSE new_list "${dir}/${pattern}")
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        SET(dir_list ${dir_list} ${file_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

MACRO(RECURSIVE_FIND_FILE_EXCLUDE_DIR return_list dir exclude_dir pattern)
    FILE(GLOB_RECURSE new_list "${dir}/${pattern}")
    SET(dir_list "")
    FOREACH(file_path ${new_list})
    IF (file_path MATCHES ".*\/${exclude_dir}\/.*")
        continue()
        endif()
        SET(dir_list ${dir_list} ${file_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

MACRO(RECURSIVE_FIND_FILE_APPEND return_list dir pattern)
    RECURSIVE_FIND_FILE( append_list ${dir} ${pattern} )
    LIST(APPEND ${return_list} ${append_list})
ENDMACRO()
