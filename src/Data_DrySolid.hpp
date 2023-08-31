#pragma once

#include <string>

class MyData {
public:
	enum class MyFormat {
		kText,
		kHTML,
		kJSON
	};

	virtual std::string print() const noexcept {
		return "Ошибка формата! Формат не задан.";
	};

	virtual ~MyData() = default;

protected:
	std::string m_data;
};

class Text : public MyData {
public:
	explicit Text(const std::string& data) : MyData() {
		m_data = data;
	}

	MyData::MyFormat getFormat() {
		return m_format;
	}

	std::string print() const noexcept override {
		if (m_format == MyFormat::kText)
			return m_data;
		else
			return MyData::print();
	}

private:
	MyData::MyFormat m_format = MyData::MyFormat::kText;
};

class HTML : public MyData {
public:
	explicit HTML(const std::string& data) : MyData() {
		m_data = data;
	}

	MyData::MyFormat getFormat() {
		return m_format;
	}

	std::string print() const noexcept override {
		if (m_format == MyFormat::kHTML)
			return "<html>" + m_data + "<html/>";
		else
			return MyData::print();
	}

private:
	MyData::MyFormat m_format = MyData::MyFormat::kHTML;
};

class JSON : public MyData {
public:
	explicit JSON(const std::string& data) : MyData() {
		m_data = data;
	}

	MyData::MyFormat getFormat() {
		return m_format;
	}

	std::string print() const noexcept override {
		if (m_format == MyFormat::kJSON)
			return "{ \"data\": \"" + m_data + "\" }";
		else
			return MyData::print();
	}

private:
	MyData::MyFormat m_format = MyData::MyFormat::kJSON;
};
