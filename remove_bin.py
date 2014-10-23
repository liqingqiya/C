#!/usr/bin/python
#-*- coding:utf-8 -*-

import os
import pdb


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

remove_file = os.remove

def main(root=".", cmd="ls -l"):
    #pdb.set_trace()
    tmp_file = os.popen(cmd)
    for lino, line in enumerate(tmp_file):
        if lino!=0:
            ret = get_bin_filename(line)
            if ret is not None:
                type_mes, file_path = ret
                print 'remove file: ', file_path,"\t\t", type_mes,
                remove_file(file_path)
                print '\t...done'

if __name__=="__main__":
    main()

