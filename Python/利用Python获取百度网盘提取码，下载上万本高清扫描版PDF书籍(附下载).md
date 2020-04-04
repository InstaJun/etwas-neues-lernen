本文主要介绍利用Python爬取脚本之家的PDF电子书。

![img](https://pic3.zhimg.com/80/v2-eda25631a1d9fe992aa1a45455fcd052_1440w.jpg)

**如果大家是奔着这一万五千本电子书来的，可以直接下载我之前爬好的电子书数据**。书籍主要涉及以下分类：

产品经理、设计、运营、网页制作、编程开发、图形图像、其他相关、人生励志、办公教育、网络相关、网络安全、服务器、程序基础、Python教程、C/C++/C#、Java电子书、iOS、Android、Ruby教程、VB书籍、汇编语言、Delphi、PowerBuilder、Flash/ActionScript、Perl、Matlab、编程其它、CSS教程、Javascript电子书、ASP电子书、PHP电子书、.NET电子书、ajax电子书、VBS电子书、站长书籍、HTA电子书、数据库XML、正则表达式、电脑技术、电脑报刊、电脑硬件、隋书源码、Linux_Unix、DOS批处理、VBA、TXT小说、手机相关、建站程序、认证考试、用户手册、Sqlserver、Oracle、Mysql、DB2、XML、VFP、数据库其它

链接：[https://pan.baidu.com/s/1MiMGj0L830AOjzN1uo9pVw](https://link.zhihu.com/?target=https%3A//pan.baidu.com/s/1MiMGj0L830AOjzN1uo9pVw)  提取码：8e61 

**如果大家是奔着百度网盘提取码获取来的，这里给大家推荐一个浏览器插件，安装这个插件后，打开百度云链接，可以自动获取提取码，并且自动提交**，用起来已经算是非常方便了。但是作为免费工具，采集大家的百度网盘分享链接和提取码信息肯定是少不了了，不介意的话可以直接用。

[https://extension.yunpanjingling.com/](https://link.zhihu.com/?target=https%3A//extension.yunpanjingling.com/)[extension.yunpanjingling.com](https://link.zhihu.com/?target=https%3A//extension.yunpanjingling.com/)

如果介意的话，**也可以用这个网站手动获取提取码**。当然网站是不会采集你的信息的哈～

[百度网盘提取码查询](https://link.zhihu.com/?target=https%3A//pnote.net/pan/)[pnote.net](https://link.zhihu.com/?target=https%3A//pnote.net/pan/)

------

有一天在逛同性交友网站（Github）时，发现竟然有人提交了获取百度网盘提取码的项目！想着难道提取码不是在服务端吗？没见过世面的我赶紧点进去看了一下，发现项目是基于一个叫云盘万能钥匙的API开发的。于是乎去研究了以下云盘万能钥匙这个东西，最终发现并不是破解了百度网盘的提取码，而是采集了大量的网盘分享链接和提取码存在数据库中，进行查询提取的。而且他们还建立了一个封闭的社区，将这些采集的和用户主动分享的资源进行交易获利。在如今这当口，不得不说他们胆子还挺肥的！

## 1.抓包获取百度网盘分享链接提取码提取接口和相关参数

遇到这种靠广大网友发财，胆子又肥的大兄弟，我们必须得盘他啊！话不多说，直接打开Fiddler准备抓包分析，然后找个百度云分享链接用浏览器访问，发现这个插件直接自动获取了提取码，并且为我们进行了自动填充和提交（不得不说，体验做的不错，哈哈哈~）

![img](https://pic3.zhimg.com/80/v2-432e97cd9d191c6e3c0d0964d7b4dd5a_1440w.jpg)

去看抓包数据，很明显就看到了这个获取提取码的请求。而且发现请求已经不能再简单了，只需要这三个固定参数（我们写死就可以了）：

- User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.142 Safari/537.36
- Origin: chrome-extension://anlllmnpjodopgbkbpnghnjlelnogfjc
- Host: [云盘万能钥匙 - 你的云盘智能助手](https://link.zhihu.com/?target=http%3A//ypsuperkey.meek.com.cn/)

![img](https://pic2.zhimg.com/80/v2-16f0f451d8a1edfb2871f3cfb1db5ce1_1440w.jpg)

还有一个参数就是百度云分享链接的唯一标识符（/api/v1/items/BDY-2Y_6bV4ZCZxfu8cFjCisoA），放在URL中进行拼接的，这个参数就是方便他服务端进行查询的。这个参数直接就是百度网盘分享链接的一部分（还有比这还简单的吗？就喜欢这样的，有资源大家一起共享嘛！哈哈哈~）。

![img](https://pic3.zhimg.com/80/v2-df2fcde11bf0836e5c0d02dc0b5614ce_1440w.jpg)

看都看了，顺便也看看开源的这个网站有没有做反爬虫验证吧，然后发现也没有什么验证。

![img](https://pic1.zhimg.com/80/v2-b4e29adb2ff9b8466e6227abec47fff4_1440w.jpg)

![img](https://pic1.zhimg.com/80/v2-3c5bafd42a33039c329ebf2925dfc248_1440w.jpg)

## 2.PDF书籍来源

其实发现了获取百度网盘提取码的接口后，我当时还没发现有什么用途。偶尔一次机会，同事找我帮他下载几本PDF书，然后发现了脚本之家竟然公然藏了这么多PDF书籍！而且都是百度网盘下载链接。

![img](https://pic4.zhimg.com/80/v2-dd66d4e3660688e7d34a242f5b86a8e3_1440w.jpg)

但是下载这些书籍，需要关注他家的公众号，然后回复对应的数字，获取百度网盘的提取码，不过我已经装了云盘万能钥匙插件，下载链接旁边已经显示了解锁标志，表示已经自动获取了此链接的提取码（哎呀，体验不错~），所以我不用关注即可下载了。

看到这么多高清的扫描书籍，顿时觉得这些书都是我的啊！哈哈哈~我得全部把他保存下来啊，并且记录百度网盘的提取码。日后想看什么书，直接下载就可以了，多方便，而且还有一定的收藏价值。

## 3.通过Python自动获取PDF书籍

本着平头哥”生死看淡，不服就干！“的精神，咱们说干就干！当然不是手动一个个的复制粘贴哈~当然是人生苦短，我用Python。当天下班咱就写好了糙代码。

![img](https://pic4.zhimg.com/v2-a6a780693e3d5c00cea8bcee93f45b23_b.jpg)



此次爬虫主要涉及三大块内容：

- 第一，就是爬取PDF书籍的下载链接；
- 第二，获取百度网盘链接的提取码；
- 第三，保存PDF书籍数据；

由于是一次性项目，都懒得用多进程了，直接写两个脚本，一个获取书籍下载链接的，一个获取百度网盘提取码的，然后到时候两个脚本同时运行就可以了。

**爬取PDF书籍的下载链接**

看脚本之家的书籍详情页面都是什么什么.html的形式，猜测采用的静态页设计，所以爬虫基本不会做什么参数上的反爬虫，经过验证这里只需要User-Agent、Referer、Host即可。

![img](https://pic4.zhimg.com/80/v2-a07d337bce398debfae07b8b1d1eb2d3_1440w.jpg)

所以我们只需要按照网站的书籍分类列表（这里一共有几十个分类，就不一一列出来了），配置一个爬取的起始列表页，逐个逐个的去爬，并且在爬书籍详情页的时候进行一个去重，即可获取所有书籍了。

![img](https://pic2.zhimg.com/80/v2-feffe37f3e0e7c6c1550e6a0f997c9c5_1440w.jpg)

解析上采用的是Xpath解析，也是特别简单的，几条Xpath语句即可获取到对应的百度网盘链接了。

![img](https://pic3.zhimg.com/80/v2-237221ebe3af9c7c24219261c85cf0a2_1440w.jpg)

一切都看起来非常的简单，非常适合新手入门练习。但是最终在实际跑的过程中发现爬了一会就报错了，最终检查发现几个问题：

**问题一：**由于书籍分类较多，我以为书籍应该也很多，就用了协程。但是**协程一开就发现IP被封了！并且需要大概半小时左右才会自动解封**。所以不管了，直接去掉协程并挂上代理（代理池的搭建可参考我之前的文章：https://zhuanlan.zhihu.com/p/84361860）。

**问题二：**有的书籍的没有百度网盘下载链接，但是有其他可以直接下载的链接。所以链接的解析上需要做简单的适配。

![img](https://pic4.zhimg.com/80/v2-c008cfd68c50671047d3eef4dffd957b_1440w.jpg)

到此我们第一大块内容：爬取PDF书籍的下载链接就算完成了，对应的代码如下：

```python
# coding='utf-8'
from DbOperate import DbOperate
from Config import BOOK_SORTS
from UserAgent import UserAgent
import gevent, requests, re, json, random, traceback
from lxml import etree


class Jb51Books(object):
	def __init__(self):
		self.db_operate = DbOperate()
		self.user_agent = UserAgent()
		self.sort_headers = {
			'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
			'Referer':'https://www.jb51.net/books/',
			'Host':'www.jb51.net',
			'Cache-Control':'no-cache',
			'Pragma':'no-cache',
		}
		self.detail_headers = {
			'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
			'Referer':'',
			'Host':'www.jb51.net',
			'Cache-Control':'no-cache',
			'Pragma':'no-cache',
		}

	def save(self, name, detail_link, sort, get_status, pan_link1=None, pan_link2=None, jb51_link=None):
		if(not self.db_operate.existed(name, detail_link)):
			try:
				self.db_operate.add(name, detail_link, sort, get_status, pan_link1, pan_link2, jb51_link)
			except Exception as e:
				print('名称或链接重复的书籍：%s' % detail_link)
				print({'name':name, 'detail_link':detail_link, 'sort':sort, 'get_status':get_status, 'pan_link1':pan_link1, 'pan_link2':pan_link2, 'jb51_link':jb51_link})
				traceback.print_exc()

	def get_download_link(self, book_link, sort):
		url = 'https://www.jb51.net/' + book_link
		if(not self.db_operate.existed(None, url)):
			self.detail_headers['User-Agent'] = self.user_agent.get_pc_ua()
			for n in range(1, 4):
				try:
					proxies = self.get_proxy()
					res = requests.get(url, headers=self.detail_headers, proxies=proxies, timeout=5)
				except:
					res = False
				else:
					break
			if(not res):
				try:
					res = requests.get(url, headers=self.detail_headers, timeout=5)
				except:
					res = False
					print('失败的详情链接：%s' % book_link)
			if(res):
				res.encoding = 'GBK'
				selector = etree.HTML(res.text)
				name = selector.xpath('//h1[@itemprop="name"]/text()')[0]
				pan_links = selector.xpath('//li[@class="baidu"]/a/@href')
				if(pan_links):
					pan_link1 = pan_links[0]
					try:
						pan_link2 = pan_links[1]
					except:
						pan_link2 = None
					self.save(name, url, sort, 1, pan_link1, pan_link2)
				else:
					jb51_links = selector.xpath('//ul[@class="ul_Address"]/li/a[@rel="nofollow"]/@href')
					if(jb51_links):
						str = '; '
						jb51_link = str.join(jb51_links)
						self.save(name, url, sort, 2, jb51_link=jb51_link)
					else:
						self.save(name, url, sort, 0)
		# else:
		# 	print('名称或链接重复的书籍：%s' % url)

	def get_proxy(self):
		# 请配置自己的代理IP获取api
		res = requests.get('http://xxx/xxx/')
		j = json.loads(res.text)
		proxy = random.choice(j['data'])
		return {'http': proxy, 'https': proxy}


	'''
	# 判断是否有更新
	db_operate = DbOperate()
	create_time = db_operate.get_new_book()
	'''
	def run(self):
		for book_sort in BOOK_SORTS:
			sort = book_sort['sort']
			for n in range(1, 4):
				try:
					proxies = self.get_proxy()
					res = requests.get(book_sort['url'] + '1.html', headers=self.sort_headers, proxies=proxies, timeout=5)
				except:
					res = False
				else:
					break
			if(not res):
				try:
					res = requests.get(book_sort['url'] + '1.html', headers=self.sort_headers)
				except:
					res = False
					print('失败的分类链接：%s' % (book_sort['url'] + '1.html'))
			if(res):
				selector = etree.HTML(res.text)
				try:
					end_page = selector.xpath('//div[@class="plist"]/a[last()]/@href')[0]
					end_page_num = int(re.findall(r"_(.+?)\.", end_page)[0])
				except:
					end_page_num = 1
				finally:
					for page_num in range(1, end_page_num + 1):
						self.sort_headers['User-Agent'] = self.user_agent.get_pc_ua()
						for n in range(1, 4):
							try:
								proxies = self.get_proxy()
								res = requests.get(book_sort['url'] + str(page_num) + '.html', headers=self.sort_headers, proxies=proxies, timeout=5)
							except:
								res = False
							else:
								break
						if(not res):
							try:
								res = requests.get(book_sort['url'] + str(page_num) + '.html', headers=self.sort_headers, timeout=5)
							except:
								print('失败的分页链接：%s' % (book_sort['url'] + str(page_num) + '.html'))
						if(res):
							selector = etree.HTML(res.text)
							book_link_lists = selector.xpath('//p[@class="tit"]/a/@href')
							for book_link in book_link_lists:
								self.get_download_link(book_link, sort)
							'''
							亲测，访问太频繁，会封IP
							spawns = []
							for book_link in book_link_lists:
								spawns.append(gevent.spawn(self.get_download_link, book_link, sort))
							gevent.joinall(spawns)
							'''


if __name__ == '__main__':
	Book = Jb51Books()
	Book.run()
```

## 获取百度网盘链接的提取码

百度网盘提取码的获取，前面已经介绍了。这里我们只需要去数据库中读取已经保存的书籍下载链接，然后获取提取码之后更新数据即可。至于接口的话想用哪一个都可以哈，反正都没有反爬虫限制。对应的代码如下：

```python
# coding='utf-8'
from DbOperate import DbOperate
from UserAgent import UserAgent
import requests, json, gevent, random, time

class PanCode(object):
	def __init__(self):
		self.db_operate = DbOperate()
		self.user_agent = UserAgent()
		self.headers = {
			'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
			'referer':'https://pnote.net/pan/',
			'origin':'https://pnote.net',
			'content-type':'application/json',
			'pragma':'no-cache',
		}

	def get_proxy(self):
		# 请配置自己的代理IP获取api
		res = requests.get('http://xxx/xxx/')
		j = json.loads(res.text)
		proxy = random.choice(j['data'])
		return {'http': proxy, 'https': proxy}

	def update_book(self, id, get_code_status, pan_code1, pan_code2):
		if(pan_code1 or pan_code2):
			self.db_operate.update_code(id, 1, pan_code1, pan_code2)
		else:
			self.db_operate.update_code(id, get_code_status, pan_code1, pan_code2)

	def do_request(self, link):
		for n in range(1, 4):
			try:
				proxies = self.get_proxy()
				self.headers['user-agent'] = self.user_agent.get_pc_ua()
				res = requests.get('https://node.pnote.net/api/pan?url=' + link, headers=self.headers, proxies=proxies, timeout=5)
			except:
				res = False
			else:
				break
		if(res):
			j = json.loads(res.text)
		else:
			for n in range(1, 3):
				try:
					self.headers['user-agent'] = self.user_agent.get_pc_ua()
					res = requests.get('https://node.pnote.net/api/pan?url=' + link, headers=self.headers, timeout=5)
					j = json.loads(res.text)
				except:
					j = {'status':False}
				else:
					break
		return j

	def get_code(self, id, link1, link2):
		pan_code1 = None
		pan_code2 = None
		get_code_status = 3
		j = self.do_request(link1)
		if(j['status']):
			pan_code1 = j.get('access_code', None)
			if(pan_code1 == None):
				get_code_status = 2
		elif((link1 != link2) and get_code_status != 2):
			j = self.do_request(link2)
			if(j['status']):
				pan_code2 = j.get('access_code', None)
				if(pan_code1 == None):
					get_code_status = 2
		self.update_book(id, get_code_status, pan_code1, pan_code2)

	def run(self):
		books = self.db_operate.get_no_code()
		print(len(books))
		for book in books:
			spawns = []
			spawns.append(gevent.spawn(self.get_code, book.id, book.pan_link1, book.pan_link2))
			if(len(spawns) >= 5):
				gevent.joinall(spawns)
		gevent.joinall(spawns)
			# self.get_code(book.id, book.pan_link1, book.pan_link2)

if __name__ == '__main__':
	while(True):
		pan_code = PanCode()
		print(pan_code.run())
		time.sleep(3600)
```

**保存PDF书籍数据**

由于前面很多次爬虫都是用的sqlalchemy的orm映射完成的数据库操作，所以直接复制之前写大烂代码过来改一下字段就可以用了，毕竟下了班业余Coding也是极懒的，哈哈哈~对应的数据库字段如下：

- id：没啥用，看个数量吧；
- name：用于存储书籍名称；
- detail_link：用于存储书籍详情页的链接，可用于去重（有重复链接就不用爬取了），也可用于记录书籍详情；
- sort：书籍的分类；
- get_status：是否成功获取到下载链接：0获取失败，1百度云链接，2官方下载链接；
- get_code_status：是否成功获取提取码：0未获取，1获取成功，2无需提取码，3获取失败；
- pan_link1：百度网盘下载链接1；
- pan_code1：百度网盘下载链接1的提取码；
- pan_link2百度网盘下载链接1；
- pan_code2：百度网盘下载链接2的提取码；
- jb51_link：其他下载链接；
- create_time：创建时间；

```python
# coding='utf-8'

from sqlalchemy import Column, Integer, String, Boolean, DateTime, create_engine
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base
# from sqlalchemy.sql.expression import func
import os, datetime
import warnings
# 忽略sqlalchemy警告
warnings.filterwarnings("ignore")

# 创建对象的基类:
BaseModel = declarative_base()

# 定义图书对象
class Books(BaseModel):
    # 表的名字:
    __tablename__ = 'books'

    # 表的结构
    id = Column(Integer, primary_key=True, autoincrement=True)
    name = Column(String, unique=True)
    detail_link = Column(String, unique=True)
    sort = Column(String)
    # 是否成功获取到下载链接：0获取失败，1百度云链接，2官方下载链接
    get_status = Column(Integer)
    # 是否成功获取提取码：0未获取，1获取成功，2无需提取码，3获取失败
    get_code_status = Column(Integer, default=0)
    # 是否已保存至百度网盘：0未保存，1保存成功，2保存失败
    save_status = Column(Integer, default=0)
    pan_link1 = Column(String)
    pan_code1 = Column(String)
    pan_link2 = Column(String)
    pan_code2 = Column(String)
    jb51_link = Column(String)
    create_time = Column(DateTime(), default=datetime.datetime.utcnow)

# 数据库操作
class DbOperate(object):
    def __init__(self):
        # 初始化数据库连接:
        self.engine = create_engine('sqlite:////home/meetup/Desktop/jb51_spider/books/db.sqlite3', echo=False, connect_args={'check_same_thread': False})
        # 创建DBSession类型:
        self.DBSession = sessionmaker(bind=self.engine)
        self.session = self.DBSession()

    def create_table(self):
        # 创建BaseModel所有子类与数据库的对应关系
        BaseModel.metadata.create_all(self.engine)
    
    # 插入初始化数据
    def init_data(self):
        pass
    
    # 删除数据库
    def drop_db(self):
        BaseModel.metadata.drop_all(self.engine)

    # 添加新增的Book数据
    def add(self, name, detail_link, sort, get_status, pan_link1=None, pan_link2=None, jb51_link=None):
        self.session.add(Books(name=name, detail_link=detail_link, sort=sort, get_status=get_status, pan_link1=pan_link1, pan_link2=pan_link2, jb51_link=jb51_link))
        self.session.commit()

    def existed(self, name, detail_link):
        try:
            book1 = self.session.query(Books).filter(Books.name==name).first()
        except:
            book1 = False
        try:
            book2 = self.session.query(Books).filter(Books.detail_link==detail_link).first()
        except:
            book2 = False
        if(book1 or book2):
            return True
        else:
            return False

    # 获取最新创建的一条Book数据
    def get_new_book(self):
        return self.session.query(Books).order_by('-create_time').first().create_time

    # 获取：未获取提取码 或者 获取提取码失败 的Books数据
    def get_no_code(self):
        # return self.session.query(Books).filter(Books.get_status==1, Books.get_code_status==0).all()
        return self.session.query(Books).filter(Books.get_status==1, Books.get_code_status==0).all() + self.session.query(Books).filter(Books.get_status==1, Books.get_code_status==3, Books.pan_link1.like('%pan.baidu.com%')).all()

    # 更新Book的提取码
    def update_code(self, id, get_code_status=1, pan_code1=None, pan_code2=None):
        book = self.session.query(Books).get(id)
        if(get_code_status == 1):
            book.pan_code1 = pan_code1
            book.pan_code2 = pan_code2
            book.get_code_status = 1
        else:
            book.get_code_status = get_code_status
        self.session.commit()

if __name__ == '__main__':
    db_operate = DbOperate()
    books = db_operate.get_no_code()
    print(len(books))
    # book = db_operate.existed('USB 2.0与OTG规范及开发指南 PDF扫描版[44MB]', None)
    # print(book)
    # if(not book):
    #     print('不重复')
    # else:
    #     print('重复')
    # db_operate.create_table()
#     db_operate.add('H5+移动营销设计宝典 高清pdf完整版 含epub+azw3', 'https://www.jb51.net/books/661726.html', '网页制作', 1, 'https://pan.baidu.com/s/1GEuENuVJFttlRStwfZ-_Jw', 'https://pan.baidu.com/s/1GEuENuVJFttlRStwfZ-_Jw')
#     db_operate.update_code(1, 1, '1234')
```

## 扩展补充：

有兴趣的朋友还可以做一些拓展内容：

- 比如做一个检测各个书籍分类列表下是否有书籍更新的方法，如果检测到有更新，继续爬取新更新的书籍。大致思路就是获取分类下的最新文章，判断此文章链接在数据的相同分类中是否存在，如果不存在表示有更新。爬的时候，检测到相同分类下，数据库已存在当前爬取的书籍，然后就break出来；
- 比如做一个将这些书籍自动保存到自己的百度网盘中，并且按照书名去重命名文件。思路就是获取百度网盘的各种操作接口，这些接口，大佬都替你找好了，GitHub上搜索就有了哈。然后账号登录上可以先自行在网页上登录，然后获取登录的cookie，带上这个cookie去请求百度网盘对应的接口就可以了哈；

由于个人对这些书籍的需求并不大，而且还怕掉头发。偶尔看一下，手动下载即可。代码也是之前一时兴起写的，所以就不去完善了，哈哈哈~

------

**本人职业产品汪，爱好设计，业余Coding。代码写的贼糙，大佬轻喷！**

**更多Python爬虫方面的小技巧和项目实战，欢迎关注我的专栏：**

[Python爬虫实用小技巧与项目实战](https://zhuanlan.zhihu.com/python-spider)

[zhuanlan.zhihu.com![图标](https://pic2.zhimg.com/v2-0545b9450e40f64ee72dd8cd281a4ea9_ipico.jpg)](https://zhuanlan.zhihu.com/python-spider)

编辑于 2019-10-07

「能获得你的赏