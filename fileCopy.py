from docx import Document

def copy_file(orig_file_path, copy_file_path):
    doc = Document(orig_file_path)
    doc.save(copy_file_path)
    print("================ \n" + "copying finished \n" + "================ \n")

if __name__ == "__main__":
    u_orig_file_path = 'C:/qt_projects/Python_hybrid_test/file_editing/test_2.docx'
    u_copy_file_path = 'C:/qt_projects/Python_hybrid_test/file_editing/copy_test3.docx'
    copy_file(u_orig_file_path, u_copy_file_path)