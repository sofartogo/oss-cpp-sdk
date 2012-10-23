/*
 * =============================================================================
 *
 *       Filename:  mainpage.h
 *
 *    Description:  mainpage content
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/** @mainpage OSSCPP 开发者手册
*******************************************************************************
* @section OSSCPP介绍 
* @subpage OSSCPP_INTRO
* @subsection 关于OSS
* 阿里云存储服务(OpenStorageService,简称 OSS)，是阿里云对外提供的海量，安全，低成本，高可靠的云存储服务。
* 用户可以通过简单的 REST 接口，在任何时间、任何地点、任何互联网设备上进行上传和下载数据，
* 也可以使用WEB 页面对数据进行管理。同时，OSS 提供 Java、Python、PHP SDK,简化用户的编程。
* 基于 OSS，用户可以搭建出各种多媒体分享网站、网盘、个人企业数据备份等基于大规模数据的服务。
* 【摘自《OSS API 开放接口规范文档》】。
*
* @subsection 我们为OSS做了什么？
* 本项目为阿里云开放存储服务（OSS）提供了一套完整易用的 C++ SDK，并取名为 OSSCPP，
* 目前 OSSCPP 提供了 OSS 开放接口中所描述的所有功能, 特点包括：
* -# Bucket 所有操作，如创建 Bucket、删除 Bucket、获取某个 Bucket 访问权限、设置 Bucket 访问权限、获取所有 Bucket 信息、
* 获取 Bucket 中所有 Object 的信息。
* -# Object 所有操作，创建 Object，获取 Object，删除 Object，获取 Object 元信息，拷贝 Object，一次性删除多个 Object，另外，还在此基础上\n
* 实现了从文件上传 Object、从内存缓冲区上传 Object、下载 Object 至文件、下载 Object 至内存缓冲区。
* -# Multipart Upload 操作，初始化 Multipart Upload、上传 Part、完成 Multipart 上传、终止 Multipart Upload、查看 Multipart Upload，查看正在上传的 Part。
* -# Object Group 操作，创建 Object Group，获取 Object Group，获取 Object Group 中的 Object List 信息、获取 Object Group 元信息，删除 Object Group。
*
*******************************************************************************
* @section OSSCPP安装细节
* @subpage OSSCPP_INSTALL
* @subsection 操作系统
* OSSCPP 在 Ubuntu 12.04 上开发，我们测试了OSSCPP在不同Linux操作系统发行版的稳定性，以下是OSSCPP经过测试操作系统：
* - Ubuntu 12.04, 11.10, 11.04, 10.10, 10.04
* - CentOS 5.5
* - Fedora 15, 16, 17
* - openSUSE 12.2
*
* @subsection OSSCPP依赖库
* OSSCPP 采用 CURL 库处理 HTTP 请求，因此在编译 OSSCPP 之前你需要安装 CURL，CURL 源码中包含了C调用API，最新版 CURL下载地址：http://curl.haxx.se/libcurl/。
* 除此之外，OSSCPP 不依赖任何其他程序库。
*
* @subsubsection CURL安装
* 本节介绍如何编译 CURL
*
* -# 下载 CURL，http://curl.haxx.se/download.html
* -# 安装 CURL，在Unix/Linux按照如下步骤，
* @code
* $ ./configure
* $ make
* $ make test (optional)
* $ make install(需root用户权限)
* @endcode
* 你也可以参考 CURL 的官方安装文档，http://curl.haxx.se/docs/install.html
* -# 完成依赖库安装后执行 ldconfig（需root用户权限）
*
* @subsection OSSCPP编译步骤
* 本节介绍如何编译OSSCPP。
*
* OSSCPP采用 CMake 管理构建过程，应该先安装CMake，
* -# 安装CMake。
* -# 创建 build 目录，进入到该目录，执行 cmake ../.
* -# 编译和安装 make && make install
*
* OSSCPP默认安装在 /usr/local目录下，当然你可以在 cmake 中设置。
*
* @subsection 在你的程序中使用OSSCPP
* OSSCPP以程序库的形式提供给上层开发者使用，因此如果你想基于OSSCPP开发上层应用，必须链接OSSCPP程序库，OSSCPP大部分都集中到了 osscppcore 中。
* 以下是你的程序需要连接OSSCPP，链接参数为：-L/path-to-your-osscpp-installation -losscppcore.
*
*******************************************************************************
* @section OSSCPP编码规范
* @subpage OSSCPP_CODING_STYLE
*
* 一个优秀的项目必须遵循良好的编码规范，良好的编码风格可以促进团队协作，减少 BUG 产生几率，有助于开发后的代码审查，降低后期维护成本。
*
* OSSCPP虽然只是我们在业余时间完成的小项目，但是也注重的编码风格的一致性，我们强烈建议那些希望基于OSSCPP做二次开发的编码人员阅读本规范，
* 相信本规范能够让你快速熟悉 OSSCPP 的整体结构和OSSCPP API 的使用方法。
*
*******************************************************************************
* @section OSSCPP实现原理
* OSSCPP详细的实现原理请参考：\subpage OSSCPP_INTERNAL
*
*******************************************************************************
* @section API使用示例
*
* @subpage OSSCPP_API_EXAMPLE
*******************************************************************************
* @section 关于OSSCPP授权 
* OSSC 使用的开源程序：
* -# GNUlib 中的 base64, sha1, hmac-sha1等模块，并进行了适当改造。
* -# CCAN 的 ttxml，一个极简单的 xml 文件只读库
* -# tinyxml 
*
* OSSCPP 采用 LGPL（GNU Lesser General Public License：GNU 宽通用公共许可证）授权形式发布，有关 LGPL 你可以查阅 GNU 官方文档：
* http://www.gnu.org/licenses/lgpl.html
*******************************************************************************
* @section 关于作者
* 傅海平：中国科学院计算技术研究所网络数据中心(haipingf@gmail.com)\n
* 王  维：中国科院学计算技术研究所网络数据中心(wangwei881116@gmail.com)
*/


/////////////////////////////////////////////////////////////////////////////////////////////////////
/** @page OSSCPP_INTRO OSSCPP详细介绍
 * @section OSSCPP介绍
 * @subsection OSS 简介
* 阿里云存储服务(OpenStorageService,简称 OSS)，是阿里云对外提供的海量，安全，低成本，高可靠的云存储服务。
* 用户可以通过简单的 REST 接口，在任何时间、任何地点、任何互联网设备上进行上传和下载数据，
* 也可以使用WEB 页面对数据进行管理。同时，OSS 提供 Java、Python、PHP SDK,简化用户的编程。
* 基于 OSS，用户可以搭建出各种多媒体分享网站、网盘、个人企业数据备份等基于大规模数据的服务。
* 【摘自《OSS API 开放接口规范文档》】。
*
* @subsection OSSCPP概述
* 本项目为阿里云开放存储服务（OSS）提供了一套完整易用的 C++ SDK，并取名为 OSSCPP，
* 目前 OSSCPP 提供了 OSS 开放接口中所描述的所有功能, 特点包括：
* - Bucket 所有操作，如创建 Bucket、删除 Bucket、获取某个 Bucket 访问权限、设置 Bucket 访问权限、获取所有 Bucket 信息、
* 获取 Bucket 中所有 Object 的信息。
*
* - Object 所有操作，创建 Object，获取 Object，删除 Object，获取 Object 元信息，拷贝 Object，一次性删除多个 Object，另外，还在此基础上\n
* 实现了从文件上传 Object、从内存缓冲区上传 Object、下载 Object 至文件、下载 Object 至内存缓冲区、多线程断点续传上传大文件，断点续传下载文件。
*
* - Multipart Upload 操作，初始化 Multipart Upload、上传 Part、完成 Multipart 上传、终止 Multipart Upload、查看 Multipart Upload，查看正在上传的 Part。
*
* - Object Group 操作，创建 Object Group，获取 Object Group，获取 Object Group 中的 Object List 信息、获取 Object Group 元信息，删除 Object Group。
*
* @subsection 我们的夙愿
* 我们是 OSSCPP（OSS C++ SDK） 的开发者，OSSCPP 为阿里云开放存储服务（OSS）提供了一套完整易用的 C++ SDK，在功能上完全实现了 OSS 开放接口，所以就功能而言，OSSCPP 已经达到在生产环境中使用的级别。
*
* 但是由于时间仓促，加上我们自身能力的有限，OSSCPP 目前不是十分完美，我们将它开源贡献出来，希望今后更多的人参与到 OSSCPP 项目上来，提高 OSSCPP 的稳定性，希望借此促进阿里云开放存储服务OSS的发展，同时我们也为开源贡献力量。
*
*/

/** @page OSSCPP_INSTALL OSSCPP安装步骤
* @section OSSCPP安装步骤
* @subsection OSSCPP依赖库
* OSSCPP 采用 CURL 库处理 HTTP 请求，因此在编译 OSSCPP 之前你需要安装 CURL，CURL 源码中包含了C调用API，最新版 CURL下载地址：http://curl.haxx.se/libcurl/。
* 除此之外，OSSCPP 不依赖任何其他程序库。
*
* @subsubsection CURL安装
* 本节介绍如何编译 CURL
*
* -# 下载 CURL，http://curl.haxx.se/download.html
* -# 安装 CURL，在Unix/Linux按照如下步骤，
* @code
* $ ./configure
* $ make
* $ make test (optional)
* $ make install(需root用户权限)
* @endcode
* 你也可以参考 CURL 的官方安装文档，http://curl.haxx.se/docs/install.html
* -# 完成依赖库安装后执行 ldconfig（需root用户权限）
*
* @subsection OSSCPP编译步骤
* 本节介绍如何编译OSSCPP。
*
* OSSCPP采用 CMake 管理构建过程，应该先安装CMake，
* -# 安装CMake。
* -# 创建 build 目录，进入到该目录，执行 cmake ../.
* -# 编译和安装 make && make install
*
* OSSCPP默认安装在 /usr/local目录下，当然你可以在 cmake 中设置。
*
* @subsection 在你的程序中使用OSSCPP
* OSSCPP以程序库的形式提供给上层开发者使用，因此如果你想基于OSSCPP开发上层应用，必须链接OSSCPP程序库\n
* 以下是你的程序需要连接OSSCPP，链接参数为：-L/path-to-your-osscpp-installation -losscppcore.
*
 */

/** @page OSSCPP_CODING_STYLE OSSCPP编码规范详述
* @section 编码规范的重要性
* 如前文所述，一个优秀的项目必须遵循良好的编码规范，良好的编码风格可以促进团队协作，减少 BUG 产生几率，有助于开发后的代码审查，降低后期维护成本。
* @section OSSCPP编码规范概述
* -# 每个模块的类名采用单词首字母大写合成的方式命名（例如ObjectListing）\n
* -# 模块类成员的get和set方式分别例如（ObjectList::bucket_name() 和 ObjectListing::set_bucket_name(const string &bucket_name)）\n
* -# 功能类的成员函数也是采用单词首字母大写合成的方式命名,例如（Client::CreateBucket）\n
*
* 下面的代码概括了使用 OSSCPP 的步骤(获取bucket权限的示例)：
* @code
* static const string access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
* static const string access_key = "MUltNpuYqE";  //设置用户密码
* static const string endpoint = "storage.aliyun.com";    //设置hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";    //设置bucket_name
* 
* 	AccessControlList acl;
* 	acl = client.GetBucketAcl(bucket_name, retcode);
* 	Owner owner;
* 	cout << "get_bucket_acl result:" << endl << endl;
* 	if(retcode == 0) {
* 		cout << "get_bucket_acl successfully." << endl;
* 		owner = acl.owner();
* 		cout << "grant = " << acl.grant() << endl 
* 			<< "id = " << owner.id() << endl
* 			<< "display_name = " << owner.display_name() << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 	return 0;
* }
* @endcode
*
* @section 源码目录介绍
* OSSCPP 的源码目录如下：
* @code
* .
* ├── AUTHORS
* ├── build
* ├── CMakeLists.txt
* ├── doc
* ├── include
* ├── LICENSE.txt
* ├── README.txt
* ├── src
* ├── example
* @endcode
*
* 其中
* - AUTHORS文件是作者（包括贡献者）的基本信息；
*
* - build 目录是构建目录，建议在该目录下构建 OSSCPP，实际上由于 OSSCPP 采用的是 CMake OUT-OF-SOURCE 构建方式，所以只能在该目录下编译 OSSCPP；
*
* - CMakeList.txt 是项目的顶级 CMake 脚本；
*
* - doc 目录包含了 OSSCPP 的所有文档；
*
* - include目录是包含了OSSCPP 所需的头文件；
*
* - LICENSE.txt 是OSSCPP的项目采用的开源条款；
*
* - README.txt是说明文档；
*
* - src是OSSCPP的全部源码；
*
* - example目录包含了 OSSCPP 的实际使用例子。
*
* @subsection 其他命名规则
* 其他命名规则比较宽泛，OSSCPP 不作严格要求。
*
* @section 排版
* 以下内容部分参考:
* @sa https://innosoc.googlecode.com/files/%E7%BC%96%E7%A8%8B%E8%A7%84%E8%8C%83.pdf
* @subsection 缩进与对齐
* 缩进代码统一采用 4 格缩进,4 个空格或 Tab 字符,若采用 Tab 字符,应调整编辑器将 Tab 宽度设置为 4。另外，不要在代码中混合使用 Tab 和空格来进行缩进。
* @subsection 放置花括号
* 对于 if, for, while 等关键字，起始花括号放在该行的末尾，而对于函数的起始花括号则新起一行放置.
*
* @subsection 空格
* - 双目运算符两侧,需要留有空格。如 “=”, “+=”,“>=”, “<=”, “+”, “&&”, “<<”, “^”等。
*
* - if, for, while, switch 等关键字之后,与紧接着的左括号‘(’之间,要留有一个空格。
*
* - 左花括号“{”之前，右括号“)”与左花括号“{”之间要留一空格。
*
* - 函数参数之间逗号‘,’分隔后面要留有空格。
*
* - for 语句分号‘;’分隔后面要留有空格。
*
* @subsection 空行
* - 函数定义的前后,均需要适当的空行。
*
* - 在函数体内,在一组变量定义完之后,需要适当空行。
*
* - 一段逻辑性相关的代码前后需要加空行。
*
* @subsection 代码行
* - 一行代码宽度应不超过 80 个字符,对于较长的语句,应该分行书写,增加代码的可读性。
*
* @section 注释
* OSSCPP 采用 Doxygen 进行文档维护，具体注释风格与 JAVADOC 一致，参见 Doxygen 官方网站。@sa http://www.stack.nl/~dimitri/doxygen/docblocks.html
*
* 另外，OSSCPP 头文件和实现文件开头均加上了如下语句：
* @code
* /\*
*  * =============================================================================
*  *
*  *       Filename:  oss_part_listing.h
*  *
*  *    Description:  oss_part_listing.
*  *
*  *        Created:  09/04/2012 08:57:48 PM
*  *
*  *        Company:  ICT ( Institute Of Computing Technology, CAS )
*  *
*  *
*  * =============================================================================
*  *\/
* @endcode
*
*/

/** @page OSSCPP_INTERNAL OSSCPP实现原理
 *
 * @section 代码目录结构
 * @code
 * .
 * ├── AUTHORS
 * ├── CMakeLists.txt
 * ├── doc
 * ├── include
 * │   └── osscpp
 * ├── LICENSE.txt
 * ├── README.txt
 * └── src
 *     ├── CMakeLists.txt
 *     ├── lib
 *     ├── modules
 *     └── util
 *
 * @endcode
 *
 * OSSCPP 采用 CMake 管理项目构建过程，源码主要存放在 src 中，头文件在存放在 include 中，其中 include 目录结构如下：
 * @code
 * ├── osscpp
 *     ├── modules
 *     ├── oss_constants.h
 *     ├── client.h
 *     └── util
 * @endcode
 * 如编码规范一节所述，modules目录主要存放了各个模块类的头文件，你不应该直接包含include这些头文件，因为modules下的头文件开始都包含了以下语句（各个头文件可能不同）：
 * @code
 * #ifndef _OSS_PART_LISTING_H
 * # error Never include <osscpp/modules/oss_part_listing.h> directly,
 * # error use <osscpp/client.h> instead.
 * #endif
 * @endcode
 *
 * 如果你想使用 OSSCPP 的 API，你可以只包含 osscpp/client.h文件即可, 如下代码所示：
 *
 * @code
 * #include <osscpp/client.h>
 * @endcode
 *
 * 另外，src 目录结构如下：
 * @code
 * .
 * ├── CMakeLists.txt
 * ├── lib
 * ├── modules
 * └── util
 * @endcode
 * - CMakeLists.txt: 该目录的CMake脚本;
 * - lib: OSSCPP 的依赖库，包括 md5，hmac-sha1，sha1，base64等功能；
 * - modules: OSSCPP 各个类实现代码；
 * - util: OSSCPP 的工具函数，签名验证函数，时间等
 * 
 * @section 签名验证
 * OSSCPP签名验证步骤遵循OSS标准签名验证方式，具体方式详见《OSS开放接口规范》
 *
 * @section 请求处理
 * 我们使用 libcurl 发送请求并接受返回结果。libcurl 可以灵活处理多种网络协议，对于HTTP协议来说，
 * 也可以灵活地生成请求方式和请求头部。
 *
 * @section 返回结果解析与处理
 * 由于返回结果可能是包含错误信息的XML格式文件,我们选择了超轻量级的CCAN的ttxml库（http://ccodearchive.net/info/ttxml.html,一个xml文件只读库，
 * 源码仅仅300行左右），我们并对它进行了适当的改造，所以返回结果解析与处理比较完整，详细实现请参考 src/lib/ttxml和相关文件。
 *
 */

/** @page OSSCPP_API_EXAMPLE OSSCPP API 使用示例
* @attention 最新示例代码位于 example 目录中，如果需要测试示例代码，
* 请编译example中的例子（亲，默认已经编译好了，你可以直接去 build/example 的各个子目录中找到可执行文件啦:-)）
*
* @section Bucket操作
* @subsection 创建Bucket
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";       //设置bucket_name
* 
* 	client.CreateBucket(bucket_name, retcode);
* 	if(retcode == 0) {
* 		cout << "create bucket successfully." << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
*
* @endcode
* @subsection 获取Bucket的ACL信息
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
* static const string access_key = "MUltNpuYqE";  //设置用户密码
* static const string endpoint = "storage.aliyun.com";    //设置hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";    //设置bucket_name
* 
* 	AccessControlList acl;
* 	acl = client.GetBucketAcl(bucket_name, retcode);
* 	Owner owner;
* 	cout << "get_bucket_acl result:" << endl << endl;
* 	if(retcode == 0) {
* 		cout << "get_bucket_acl successfully." << endl;
* 		owner = acl.owner();
* 		cout << "grant = " << acl.grant() << endl 
* 			<< "id = " << owner.id() << endl
* 			<< "display_name = " << owner.display_name() << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 	return 0;
* }
* 
* @endcode
* @subsection 设置Bucket的ACL
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
* static const string access_key = "MUltNpuYqE";  //设置用户密码
* static const string endpoint = "storage.aliyun.com";    //设置hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果
* 	const string retinfo;            //保存通过retcode获得的错误信息
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";    //设置bucket_name
* 
* 	const string acl = "private";            //设置bucket的访问权限（private，public-read，public-read-write中的一个）
* 	client.SetBucketAcl(bucket_name, acl, retcode);
* 	printf("set_bucket_acl result:\n\n");
* 	if(retcode == 0) {
* 		cout << "set bucket acl successfully." << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
*
* @subsection 列举Bucket下的Object
* @subsubsection 按名称返回请求者指定Bucket的所有Object
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
* static const string access_key = "MUltNpuYqE";  //设置用户密码
* static const string endpoint = "storage.aliyun.com";    //设置hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果
* 	int i;
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";
* 
* 	ObjectListing object_listing = client.ListObjects(bucket_name, retcode);
* 	cout << "list_objects_with_bucket_name result:" << endl << endl;
* 	if(retcode == 0) {
* 		cout << "list_objects_with_bucket_name successfully." << endl;
* 		cout << "bucket_name = " << object_listing.bucket_name() << endl
* 			<< "next_marker = " << object_listing.next_marker() << endl
* 			<< "prefix = " << object_listing.prefix() << endl
* 			<< "marker = " << object_listing.marker() << endl
* 			<< "max_keys = " << object_listing.max_keys() << endl
* 			<< "delimiter = " << object_listing.delimiter() << endl
* 			<< "is_truncated = " << object_listing.is_truncated() << endl; 
* 		for(i = 0; i < object_listing.summaries().size(); i++) {
* 			cout << "****************************************************************" << endl;
* 			cout << "object [" << i << "] : " << endl;
* 			cout << "type = " << (object_listing.summaries())[i].type() << endl 
* 				<< "etag = " << (object_listing.summaries())[i].etag() << endl
* 				<< "key = " << (object_listing.summaries())[i].key() << endl
* 				<< "last_modified = " << (object_listing.summaries())[i].last_modified() << endl
* 				<< "size = " << (object_listing.summaries())[i].size() << endl 
* 				<< "storage_class = " << (object_listing.summaries())[i].storage_class() << endl
* 				<< "id = " << (object_listing.summaries())[i].owner().id() << endl
* 				<< "display_name = " << (object_listing.summaries())[i].owner().display_name() << endl;
* 		}
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
* @subsubsection 按请求参数返回请求者指定Bucket下的所有Object列表
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果
* 	int i;
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";
* 	ListObjectsRequest request;
* 	request.set_bucket_name(bucket_name);
* 	request.set_prefix("fun/");          //设置prefix
* 	request.set_delimiter("/");      //设置delimiter
* 	request.set_max_keys(3);      //设置max_keys
* 	request.set_marker("a");         //设置marker
* 
* 
* 
* 	ObjectListing object_listing = client.ListObjects(request, retcode);
* 	cout << "list_objects_with_bucket_name result:" << endl << endl;
* 	if(retcode == 0) {
* 		cout << "list_objects_with_bucket_name successfully." << endl;
* 		cout << "bucket_name = " << object_listing.bucket_name() << endl 
* 			<< "next_marker = " << object_listing.next_marker() << endl
* 			<< "prefix = " << object_listing.prefix() << endl
* 			<< "marker = " << object_listing.marker() << endl
* 			<< "max_keys = " << object_listing.max_keys() << endl
* 			<< "delimiter = " << object_listing.delimiter() << endl
* 			<< "is_truncated = " << object_listing.is_truncated() << endl; 
* 		for(i = 0; i < object_listing.summaries().size(); i++) {
* 			cout << "****************************************************************" << endl;
* 			cout << "object [" << i << "] : " << endl;
* 			cout << "type = " << (object_listing.summaries())[i].type() << endl 
* 				<< "etag = " << (object_listing.summaries())[i].etag() << endl
* 				<< "key = " << (object_listing.summaries())[i].key() << endl
* 				<< "last_modified = " << (object_listing.summaries())[i].last_modified() << endl
* 				<< "size = " << (object_listing.summaries())[i].size() << endl 
* 				<< "storage_class = " << (object_listing.summaries())[i].storage_class() << endl
* 				<< "id = " << (object_listing.summaries())[i].owner().id() << endl
* 				<< "display_name = " << (object_listing.summaries())[i].owner().display_name() << endl;
* 		}
* 		cout << "==================================================================" << endl;
* 		for(i = 0; i < object_listing.common_prefixes().size(); i++) {
* 			cout << "common_prefix = " << (object_listing.common_prefixes())[i] << endl;
* 		}
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
* 
* @subsection 获取所有的Bucket
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
* static const string access_key = "MUltNpuYqE";  //设置用户密码
* static const string endpoint = "storage.aliyun.com";    //设置hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果
* 	const string retinfo;            //保存通过retcode获得的错误信息
* 
* 	Client client(access_id, access_key, endpoint);
* 
* 	int i;
* 	vector<Bucket> buckets;
* 	Owner owner;
* 	buckets = client.ListBuckets(retcode);
* 	cout << "list buckets result:" << endl << endl;
* 	if(retcode == 0) {
* 		cout << "list buckets successfully." << endl;
* 		if(buckets.size() != 0) {
* 			for(i = 0; i < buckets.size(); i++) {
* 				cout << "***********************************************************************" << endl;
* 				cout << "bucket [" << i << "] : " << endl;
* 				cout << "name = " << buckets[i].name() 
* 					<< "\tcreate_date = " << buckets[i].create_date() << endl;
* 				owner = buckets[i].owner();
* 				cout << "id = " << owner.id() <<
* 					"\tdisplay_name = " << owner.display_name() << endl;
* 			}
* 		} else {
* 			cout << "empty bucket list." << endl;
* 		}
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
*
* @endcode
* @subsection 删除Bucket
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "abucket_example";       //设置bucket_name
* 
* 	client.DeleteBucket(bucket_name, retcode);
* 	cout << "delete_bucket result:" << endl << endl;
* 	if(retcode == NO_CONTENT) {
* 		cout << "delete bucket successfully." << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
*
* @endcode
*
* @section Object操作
* @subsection 上传Object
* @subsubsection 从文件上传Ojbect至OSS服务器
* @code

* #include <osscpp/client.h>
* #include <iostream>
* #include <fstream>
* #include <string>
* #include <sstream>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; ///设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; /// 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* long
* _GetFileSize(FILE *fp)
* {
*     long int save_pos;
*     long size_of_file;
*     save_pos = ftell(fp);
*     fseek(fp, 0L, SEEK_END);
*     size_of_file = ftell(fp);
*     fseek(fp, save_pos, SEEK_SET);
*     return size_of_file;
* }
*
* int main()
* {
* 
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key         = "put-ojbect.data";      //设置上传key
* 	const string local_file  = "proactor.pdf";         //设置需要上传的文件
* 	unsigned int retsize = 0; // 读取文件时的返回值
* 
* 	FILE *fp = fopen(local_file.c_str(), "r");
* 	if (fp == NULL) {
* 		return -1;
* 	}
* 	long file_len = _GetFileSize(fp);
* 	stringstream ss;
* 	ss << file_len;
* 
* #if 1
* 	// 初始化元信息，并设置相关属性 
* 	ObjectMetadata metadata;
* 	metadata.set_content_length(ss.str()); 
* 	metadata.set_content_type("application/octet-stream");
* 	metadata.set_cache_control("no-cache");
* 	metadata.set_content_encoding("utf-8");
* 	metadata.set_content_disposition("attachment;");
* 	metadata.set_expiration_time("Thu, 13 Sep 2012 21:08:42 GMT");
* #endif
* 	// 将文件上传至云服务器中
* 	PutObjectResult result = client.PutObjectFromFile(
* 			bucket_name, key, local_file, metadata, retcode);
* 	if(retcode == 0) {
* 		cout << "put object successfully." << endl;
* 		cout << "ETag: " << result.etag() << endl;
* 	} else {
* 		cout << "failed to put object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 	fclose(fp);
* }
* 
* @endcode
* @subsubsection 从内存块上传Ojbect至OSS服务器
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <fstream>
* #include <string>
* #include <sstream>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; // 设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* long
* _GetFileSize(FILE *fp)
* {
*     long int save_pos;
*     long size_of_file;
*     save_pos = ftell(fp);
*     fseek(fp, 0L, SEEK_END);
*     size_of_file = ftell(fp);
*     fseek(fp, save_pos, SEEK_SET);
*     return size_of_file;
* }
* // 将内存中的内容上传至云服务器中 
* int main()
* {
* 
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key         = "put-ojbect.data";      //设置上传key
* 	const char *local_file  = "proactor.pdf";         //设置需要上传的文件
* 	unsigned int retsize = 0; // 读取文件时的返回值
* 
* 	FILE *fp = fopen(local_file, "r");
* 	if (fp == NULL) {
* 		fprintf(stderr, "error in opening file %s\n", local_file);
* 		return -1;
* 	}
* 
* 	long file_len = _GetFileSize(fp);
* 	stringstream ss;
* 	ss << file_len;
* 	char *buffer = (char *)malloc(sizeof(char) * file_len + 1);
* 
* 	memset(buffer, '\0', file_len + 1);
* 	retsize = fread(buffer, 1, file_len, fp);
* 
* 	if (retsize < 0) {
* 		fprintf(stderr, "error in reading file %s.\n", local_file);
* 		return -1;
* 	}
* #if 1
* 	// 初始化元信息，并设置相关属性 
* 	ObjectMetadata metadata;
* 	metadata.set_content_length(ss.str()); // 该参数必须设置 
* 	metadata.set_content_type("application/octet-stream");
* 	metadata.set_cache_control("no-cache");
* 	metadata.set_content_encoding("utf-8");
* 	metadata.set_content_disposition("attachment;");
* 	metadata.set_expiration_time("Thu, 13 Sep 2012 21:08:42 GMT");
* #endif
* 	// 将内存中的内容上传至云服务器中 
* 	PutObjectResult result = client.PutObjectFromBuffer(
* 			bucket_name, key, buffer, file_len, metadata, retcode);
* 	if(retcode == 0) {
* 		cout << "put object successfully." << endl;
* 		cout << "ETag: " << result.etag() << endl;
* 	} else {
* 		cout << "failed to put object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 	free(buffer);
* }
* 
* @endcode
*
* @subsection 获取Object
* @subsubsection 获取Object到内存中
* @code
* 
* #include <osscpp/client.h>
* #include <iostream>
* #include <fstream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "glib-2.32.4.tar.xz"; 
* 	string local_file = "local-file.tar.xz";
* 	void *buffer = NULL;
* 	unsigned int buffer_len = 0;
* 
* 	std::ofstream ofs(local_file.c_str(), ofstream::binary);
* 	GetObjectRequest request(bucket_name, key);
* 
* 	ObjectMetadata metadata = client.GetObject(request, &buffer, buffer_len, retcode);
* 
* 	ofs.write(static_cast<char *>(buffer), buffer_len);
* 	ofs.close();
* 
* 	if(retcode == 0) {
* 		cout << "get object successfully." << endl;
* 		cout << "Content-Length: " << metadata.content_length() << endl;
* 		cout << "Content-Md5: " << metadata.etag() << endl;
* 		cout << "Content-Type: " << metadata.content_type() << endl;
* 		cout << "Last-Modified: " << metadata.last_modified() << endl;
* 	} else {
* 		cout << "failed to get object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
*
* @subsubsection 获取Object到文件中
* @code
* 
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; // 设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "glib-2.32.4.tar.x"; 
* 	string local_file = "local-file.tar.xz";
* 
* 	GetObjectRequest request(bucket_name, key);
* 	ObjectMetadata metadata = client.GetObject(request, local_file, retcode);
* 	if(retcode == 0) {
* 		cout << "get object successfully." << endl;
* 		cout << "Content-Length: " << metadata.content_length() << endl;
* 		cout << "Content-Md5: " << metadata.etag() << endl;
* 		cout << "Content-Type: " << metadata.content_type() << endl;
* 		cout << "Last-Modified: " << metadata.last_modified() << endl;
* 	} else {
* 		cout << "failed to get object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 	return 0;
* }
* 
* 
* @endcode
*
* @subsection 拷贝Object
* @subsubsection 通过指定拷贝请求来完成拷贝Object
* @code
* 
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; // 设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string source_bucket_name = "bucketname001";       //设置bucket_name
* 	const string destination_bucket_name = "bucketexamplex";       //设置bucket_name
* 	const string source_key = "glib-2.32.4.tar.xz"; 
* 	const string destination_key = "copy-of-glib-2.32.4.tar.xz"; 
* 
* 	CopyObjectResult result = client.CopyObject(source_bucket_name, source_key,
* 			destination_bucket_name, destination_key,
* 			retcode);
* 	if(retcode == 0) {
* 		cout << "copy object successfully." << endl;
* 		cout << "ETag: " << result.etag() << endl;
* 		cout << "Last Modified: " << result.last_modified() << endl;
* 	} else {
* 		cout << "failed to copy object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 	return 0;
* }
* 
* 
* @endcode
*
* @subsubsection 直接指定源和目的BucketName与Key拷贝Object
* @code
* 
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string source_bucket_name = "bucketname001";       //设置bucket_name
* 	const string destination_bucket_name = "bucketexample03";       //设置bucket_name
* 	const string source_key = "glib-2.32.4.tar.xz"; 
* 	const string destination_key = "copy-of-glib-2.32.4.tar.xz"; 
* 
* 	CopyObjectRequest request(source_bucket_name, source_key,
* 			destination_bucket_name, destination_key);
* 	CopyObjectResult result;
* 	result = client.CopyObject(request, retcode);
* 	if(retcode == 0) {
* 		cout << "copy object successfully." << endl;
* 		cout << "Last Modified: " << result.last_modified() << endl;
* 		cout << "ETAG: " << result.etag() << endl;
* 	} else {
* 		cout << "failed to copy object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* 
* @endcode
* @subsection 获取Object元信息
* @code

* #include <osscpp/client.h>
* #include <iostream>
* #include <fstream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; // 设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "glib-2.32.4.tar.xz"; 
* 	ObjectMetadata metadata = client.GetObjectMetadata(bucket_name, key, retcode);
* 
* 	if(retcode == 0) {
* 		cout << "get object successfully." << endl;
* 		cout << "Content-Length: " << metadata.content_length() << endl;
* 		cout << "Content-Md5: " << metadata.etag() << endl;
* 		cout << "Content-Type: " << metadata.content_type() << endl;
* 		cout << "Last-Modified: " << metadata.last_modified() << endl;
* 	} else {
* 		cout << "failed to get object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
*
* @subsection 删除Object
* @code
* 
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; // 设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "accumulo-1.4.0-src.tar.gz"; 
* 
* 	client.DeleteObject(bucket_name, key, retcode);
* 	if(retcode == 0) {
* 		cout << "delete object successfully." << endl;
* 	} else {
* 		cout << "failed to delete object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
*
* @subsection 一次性删除多个Object
* @code
* 
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketexample";       //设置bucket_name
* 
* 	vector<string> keys;
* 	keys.push_back("multipart-upload.data");
* 	keys.push_back("put-object.data");
* 	bool mode = true;
* 	DeleteMultipleObjectRequest request(bucket_name, keys, mode);
* 
* 	client.DeleteMultipleObject(request, retcode);
* 	if(retcode == 0) {
* 		cout << "delete multiple object successfully." << endl;
* 	} else {
* 		cout << "failed to delete multiple object" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* 
* @endcode
* 
* @section Multipart Multipart Upload操作
*
* @subsection 初始化Multipart-Upload操作
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "accumulo-1.4.0-src.tar.gz"; 
* 
* 	InitiateMultipartUploadRequest request(bucket_name, key);
* 	InitiateMultipartUploadResult result = client.InitiateMultipartUpload(request, retcode);
* 	if(retcode == 0) {
* 		cout << "initiate_multipart_upload execute successfully." << endl;
* 		cout << "Upload ID: " << result.upload_id() << endl;
* 	} else {
* 		cout << "failed to initiate multipart upload" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
* @subsection 上传Part
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "accumulo-1.4.0-src.tar.gz"; 
* 
* 	// TODO: 设置upload id，此upload id由initiate multipart upload 操作返回
* 	const string upload_id = "0004CB9D8ADBD007E25D68FA4AEEBDF1";
* 
* 	FILE *fp= fopen("mysql-5.1.52.tar.gz", "r"); 
* 	if (fp == NULL) {
* 		fprintf(stderr, "error in opening file...\nplease check again before upload part !\n");
* 		return -1;
* 	}
* 	unsigned int file_len = Util::GetFileSize(fp); // 获取文件大小 
* 	
* 	char *buffer = (char *)malloc(sizeof(char) * file_len + 1);
* 	memset(buffer, '\0', file_len + 1);
* 	unsigned int file_sz = fread(buffer, 1, file_len, fp);
* 	if (file_sz < file_len) {fprintf(stderr, "fread error.\n"); return -1;}
* 	const int single_request_len = 8 * 1024 * 1024; // 每个Part的大小 
* 	int requests_num = file_len / single_request_len; // 需要多少次上传 
* 	int current_part_number = 0; // 当前上传的 Part Number 
* 
* 	UploadPartRequest request;
* 	request.set_bucket_name(bucket_name);
* 	request.set_key(key);
* 	request.set_upload_id(upload_id);
* 
* 	for (current_part_number = 0; current_part_number < requests_num + 1; current_part_number++) {
* 		// 除了最后一块的其他块，最小为 5MB，此处设置单个Part为single_request_len = 8MB 
* 		if (current_part_number < requests_num) { 
* 			request.set_part_number(current_part_number + 1);
* 			void *input_stream = buffer + current_part_number * single_request_len;
* 			request.set_input_stream(input_stream);
* 			request.set_part_size(single_request_len);
* 
* 			// 上传Part 
* 			UploadPartResult result  = client.UploadPart(request, retcode);
* 
* 			if (retcode == OK) { 
* 				cout << "PartNumber: " << result.part_number() << "," << "ETag: " << result.etag() << endl;
* 			} else { 
* 				cout << Util::GetMessageFromRetcode(retcode) << endl;
* 			}
* 		} else { 
* 			request.set_part_number(current_part_number + 1);
* 			void *input_stream = buffer + current_part_number *single_request_len ;
* 			request.set_input_stream(input_stream);
* 			request.set_part_size(file_len - single_request_len * current_part_number);
* 
* 			// 上传Part 
* 			UploadPartResult result  = client.UploadPart(request, retcode);
* 
* 			if (retcode == OK) { 
* 				cout << "PartNumber: " << result.part_number() << "," << "ETag: " << result.etag() << endl;
* 			} else { 
* 				cout << Util::GetMessageFromRetcode(retcode) << endl;
* 			}
* 		}
* 	}
* 
* 	free(buffer);
* 	fclose(fp);
* 
* 	return 0;
* }
*
* @endcode
* @subsection 完成Multipart-Upload
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* const char *etags[] = {
* 	"5EAE389C2B7DB4D7CBF36B6F125272F6",
* 	"F8EC926E209252B72CFBB775A9360E8D"
* };
* 
* int main()
* {
* 
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "accumulo-1.4.0-src.tar.gz"; 
* 
* 	// TODO: 设置upload id，此upload id由initiate multipart upload 操作返回 
* 	const string upload_id = "0004CB9D8ADBD007E25D68FA4AEEBDF1";
* 
* 	vector<PartEtag> vparts;
* 	for (int i = 0; i < sizeof(etags) / sizeof(char *); i++) {
* 		PartEtag part(i + 1, etags[i]);
* 		vparts.push_back(part);
* 	}
* 	CompleteMultipartUploadRequest request(bucket_name, key, upload_id, vparts);
* 	CompleteMultipartUploadResult result = client.CompleteMultipartUpload(request, retcode);
* 
* 	if(retcode == 0) {
* 		cout << "CompleteMultipartUpload execute successfully." << endl;
* 		cout << "ETag: " << result.etag() << endl;
* 	} else {
* 		cout << "failed!" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* @endcode
* @subsection 终止一个Multipart-Upload操作
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "accumulo-1.4.0-src.tar.gz"; 
* 	const string upload_id = "0004CB9D8ADBD007E25D68FA4AEEBDF1";
* 	
* 
* 
* 	AbortMultipartUploadRequest request(bucket_name, key, upload_id);
* 	client.AbortMultipartUpload(request, retcode);
* 	if(retcode == 0) {
* 		cout << "AbortMultipartUpload execute successfully." << endl;
* 	} else {
* 		cout << "failed!" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
*
* @endcode
*
* @subsection 列出所有正在进行的Multipart-Uploads操作
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 
* 	ListMultipartUploadsRequest request(bucket_name);
* 	MultipartUploadListing listing = client.ListMultipartUploads(request, retcode);
* 	if(retcode == 0) {
* 		cout << "ListMultipartUploads execute successfully." << endl;
* 		vector<MultipartUpload> multipart_upload = listing.multipart_uploads();
* 		vector<MultipartUpload>::iterator iter;
* 		for (iter = multipart_upload.begin(); iter != multipart_upload.end(); iter++) {
* 			cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
* 			cout << "Initiated: " << (*iter).initiated() << endl;
* 			cout << "Storage Class: " << (*iter).storage_class() << endl;
* 			cout << "Upload ID: " << (*iter).upload_id() << endl;
* 			cout << "Key: " << (*iter).key() << endl;
* 		}
* 	} else {
* 		cout << "failed!" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* @endcode
* @subsection 列出一个Multipart-Upload的所有已上传的parts
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSGmv8fkV1TDO9L"; //设置用户 Access ID 
* static const string access_key = "BedoWbsJe2"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucketname001";       //设置bucket_name
* 	const string key = "accumulo-1.4.0-src.tar.gz"; 
* 	const string upload_id = "0004CB9D8ADBD007E25D68FA4AEEBDF1";
* 	
* 
* 
* 	ListPartsRequest request(bucket_name, key, upload_id);
* 	PartListing listing = client.ListParts(request, retcode);
* 	if(retcode == 0) {
* 		cout << "ListParts execute successfully." << endl;
* 		cout << "Bucket Name: " << listing.bucket_name() << endl;
* 		cout << "Upload ID " << listing.upload_id() << endl;
* 		cout << "Storage Class: " << listing.storage_class() << endl;
* 
* 		vector<PartSummary> parts = listing.parts();
* 		vector<PartSummary>::iterator iter;
* 		for (iter = parts.begin(); iter != parts.end(); iter++) {
* 			cout << "Etag: " << (*iter).etag() << endl;
* 			cout << "Last Modified: " << (*iter).last_modified() << endl;
* 			cout << "Part Number: " << (*iter).part_number() << endl;
* 			cout << "Size: " << (*iter).size() << endl;
* 
* 		}
* 	} else {
* 		cout << "failed!" << endl;
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
* 
* @section Object Group 操作
* @subsection Post Post Object Group 操作
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* //设置要组合的Objects的etag值 
* static const char *etags[] = {
* 	"6F395BF16882D154CCB448806EA8C47D",
* 	"321F048D6C898398F3168545F6CE8551",
* 	"249697174471EEE73202E9214B037E08",
* 	"B78E7B470FA41AA5478CFB0EDFF7B2E6",
* 	"E0CA28D194BC790EF3C6236231D033A7"
* };
* 
* //设置要组合的Objects的name 
* static const char *partname[] = {
* 	"a.txt",
* 	"b.txt",
* 	"c.txt",
* 	"d.txt",
* 	"e.txt"
* };
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";       //设置bucket_name
* 	const string key = "a_group_file.dat";             //设置object group的名称
* 	int i;
* 	int n = sizeof(partname)/sizeof(char *);
* 	//构造各个Object的etag，name，ID到part_item 
* 	vector<ObjectGroupItem> part_item;
* 	for (i = 0; i < n; i++) {
* 		string etag = etags[i];
* 		string name = partname[i];
* 		int number = i + 1;
* 		ObjectGroupItem item(etag, name, number);
* 		part_item.push_back(item);
* 	}
* 	PostObjectGroupRequest request(bucket_name, key, part_item);
* 	PostObjectGroupResult result = client.PostObjectGroup(request, retcode);
* 
* 	cout << "post_obejct_group result:" << endl << endl;
* 	if(retcode == OK) {
* 		cout << "post_object_group successfully." << endl;
* 		cout << "bucket_name = " << result.bucket_name() << endl << "key = " << result.key() << endl << "etag = " << result.etag() << endl << "size = " << result.size() << endl; 
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* @endcode
*
* @subsection Get01 Get Object Group 操作
* @subsubsection 获取Object-Group到内存
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	const string bucket_name = "bucket_example";       //设置bucket_name
* 	const string key = "a_group_file.dat";             //设置object group的名称
* 	string buffer;
* 
* 	Client client(access_id, access_key, endpoint);
* 	GetObjectGroupRequest request(bucket_name, key);
* 	ObjectMetadata result = client.GetObjectGroupToBuffer(request, buffer, retcode);
* 
* 	cout << "get_obejct_group_to_buffer result:" << endl << endl;
* 	if(retcode == OK) {
* 		cout << "get_object_group_to_buffer successfully." << endl;
* 		cout << "etag = " << result.etag() << endl 
* 			<< "last_modified = " << result.last_modified() << endl
* 			<< "content_type = " << result.content_type() << endl
* 			<< "content_length = " << result.content_length() << endl; 
* 		cout << "buffer = " << endl << buffer << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
* 
* @endcode
* @subsubsection 获取Object-Group至本地文件
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	const string bucket_name = "bucket_example";       //设置bucket_name
* 	const string key = "a_group_file.dat";             //设置object group的名称
* 	const string file_name = "get_object_group";
* 
* 	Client client(access_id, access_key, endpoint);
* 	GetObjectGroupRequest request(bucket_name, key);
* 	ObjectMetadata result = client.GetObjectGroupToFile(request, file_name, retcode);
* 
* 	cout << "get_obejct_group_to_buffer result:" << endl << endl;
* 	if(retcode == OK) {
* 		cout << "get_object_group_to_buffer successfully." << endl;
* 		cout << "etag = " << result.etag() << endl 
* 			<< "last_modified = " << result.last_modified() << endl
* 			<< "content_type = " << result.content_type() << endl
* 			<< "content_length = " << result.content_length() << endl; 
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
*
* @endcode
*
* @subsection Get02 Get Object Group Index 操作
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	const string bucket_name = "bucket_example";       //设置bucket_name
* 	const string key = "a_group_file.dat";             //设置object group的名称
* 	int i;
* 
* 	Client client(access_id, access_key, endpoint);
* 	GetObjectGroupIndexResult result = client.GetObjectGroupIndex(bucket_name, key, retcode);
* 
* 	cout << "get_obejct_group_index result:" << endl << endl; 
* 	if(retcode == OK) {
* 		cout << "get_object_group_index successfully." << endl;
* 		cout << "bucket_name = " << result.bucket_name() << endl << "key = " << result.key() << endl << "etag = " << result.etag() << endl << "file_length = " << result.file_length() << endl; 
* 		printf("============================================\n");
* 		for(i = 0; i < result.group().size(); i++) {
* 			cout << "part [" << i << "] :" << endl;
* 			cout << "etag = " << (result.group())[i].etag() << endl << "part_name = " << (result.group())[i].part_name() << endl << "part_number = " << (result.group())[i].part_number() << endl << "part_size = " << (result.group())[i].part_size() << endl;
* 			printf("*****************************************\n");
* 		}
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	 return 0;
* }
* 
*
* @endcode
*
* @subsection Head Head Object Group 操作
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";       //设置bucket_name
* 	const string key = "a_group_file.dat";             //设置object group的名称
* 
* 	GetObjectGroupRequest request(bucket_name, key);
* 	request.set_modified_since_constraint("Sat, 20 Sep 2012 23:23:23 GMT");
* 	ObjectMetadata result = client.HeadObjectGroup(request, retcode);
* 	cout << "head_obejct_group result:" << endl << endl;
* 	if(retcode == OK) {
* 		cout << "head_object_group successfully." << endl;
* 		cout << "content-length = " << result.content_length() << endl 
* 			<< "content-type = " << result.content_type() << endl
* 			<< "last_modified = " << result.last_modified() << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
*
* @endcode
*
* @subsection Delete Delete Object Group 操作
* @code
* #include <osscpp/client.h>
* #include <iostream>
* #include <string>
* 
* using namespace std;
* using namespace osscpp;
* 
* static const string access_id  = "ACSfLOiddaOzejOP"; //设置用户 Access ID 
* static const string access_key = "MUltNpuYqE"; // 设置用户的 Access Key 
* static const string endpoint   = "storage.aliyun.com";    //设置 hostname
* 
* int main()
* {
* 	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;
* 
* 	Client client(access_id, access_key, endpoint);
* 	const string bucket_name = "bucket_example";       //设置bucket_name
* 	const string key = "a_group_file.dat";             //设置object group的名称
* 
* 	client.DeleteObjectGroup(bucket_name, key, retcode);
* 
* 	cout << "delete_obejct_group result:" << endl << endl;
* 	if(retcode == NO_CONTENT) {
* 		cout << "delete_object_group successfully." << endl;
* 	} else {
* 		cout << Util::GetMessageFromRetcode(retcode) << endl;
* 	}
* 
* 	return 0;
* }
*
* @endcode
*/


