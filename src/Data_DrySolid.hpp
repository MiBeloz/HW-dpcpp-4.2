#pragma once

#include <string>

enum class MyFormat {
	kText,
	kHTML,
	kJSON
};

class MyData {
public:
	MyData(const MyData&) = delete;
	MyData(MyData&&) noexcept = delete;
	MyData& operator=(const MyData&) = delete;
	MyData& operator=(MyData&&) noexcept = delete;

	virtual std::string print() const noexcept = 0;

	virtual std::string saveTo(std::ostream&) const = 0;

	virtual ~MyData() = default;

protected:
	MyData() = default;
	std::string m_data;
};

class Text : public MyData {
public:
	explicit Text(const std::string& data) {
		m_data = data;
	}

	MyFormat getFormat() {
		return m_format;
	}

	std::string print() const noexcept override {
		return m_data;
	}

	std::string saveTo(std::ostream& os) const override {
		os << m_data + '\n';
		return "Данные записаны в файл.";
	}

private:
	MyFormat m_format = MyFormat::kText;
};

class HTML : public MyData {
public:
	explicit HTML(const std::string& data) {
		m_data = data;
	}

	MyFormat getFormat() {
		return m_format;
	}

	std::string print() const noexcept override {
		return "<html>" + m_data + "<html/>";
	}

	std::string saveTo(std::ostream& os) const override {
		os << "<html>" + m_data + "<html/>\n";
		return "Данные записаны в файл.";
	}

private:
	MyFormat m_format = MyFormat::kHTML;
};

class JSON : public MyData {
public:
	explicit JSON(const std::string& data) {
		m_data = data;
	}

	MyFormat getFormat() {
		return m_format;
	}

	std::string print() const noexcept override {
		return "{ \"data\": \"" + m_data + "\" }";
	}

	std::string saveTo(std::ostream& os) const override {
		os << "{ \"data\": \"" + m_data + "\" }\n";
		return "Данные записаны в файл.";
	}

private:
	MyFormat m_format = MyFormat::kJSON;
};
