#!/usr/bin/python
#-*- coding:utf-8 -*-

import os
import os.path
import pdb


remove_file = os.remove
path_join = os.path.join
abspath = os.path.abspath


def ls(root=".", cmd="ls -l"):
    """
    exec ls
    """
    cur_cmd = " ".join((cmd, root))
    return os.popen(cur_cmd)


def get_bin_filename(ls_line):
    """
    获取二进制文件的文件名
    """
    tmplist = ls_line.split()
    type_mes, filename = tmplist[0], tmplist[8]

    #u,o,g皆为可执行且文件名不含“.”,则认为为二进制执行文件
    if type_mes[0]!='d':
        if len([i for i in type_mes if i=='x'])==3:
            if '.' not in filename:
                return type_mes, filename

def _abspath(root, filename):
    local_path = path_join(root, filename)
    return abspath(local_path)


def main(root=".", ignore=None):
    #pdb.set_trace()
    for cur_dir, sub_dir, files in os.walk(root):

        if ignore is not None:
            if ignore in cur_dir:
                continue

        #一个个目录处理
        rc = ls(cur_dir)
        for lino, line in enumerate(rc):
            if lino != 0:
                ret = get_bin_filename(line)
                if ret is not None:
                    type_mes, filename = ret
                    print 'remove file: ', filename,"\t\t", type_mes,
                    remove_file(_abspath(cur_dir, filename))
                    print '\t...done'


if __name__=="__main__":
    main(root=".", ignore="PROJECT")

