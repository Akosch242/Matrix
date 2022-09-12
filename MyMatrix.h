#ifndef _MYMATRIX_
#define _MYMATRIX_

#include <iostream>
#include <exception>

/**
 * Die Klasse MyMatrix representiert ein Matrix und ermöglicht verschiedene Operationen an Matricen durch zu führen.
 *
 * Diese Matrix innerhalbe der Klasse wird als ein eindimensionale,
 * zusammenhängendes Array dynamisch gespeichert,
 * und bei der Löschen der Instanz wird es freigegeben.
 *
 * Bei theoretischen Fehlern gibt die Klasse eine Ausnahme.
 */
namespace GHA {
	template<typename T>
	class MyMatrix {
	private:
		/**
		 * Anzahl von Zeilen innerhalb des Matrix.
		 */
		unsigned int m_row;

		/**
		 * Anzahl von Spalten innerhalb des Matrix.
		 */
		unsigned int m_column;

		/**
		 * Zeiger auf die Elementen des Matrix.
		 */
		T* pMatrix;

		/**
		 * Hilfsfunktion für die rekursive Berechnung der Determinante.
		 */
		T calcdet(MyMatrix<T> matrix, unsigned int n);
	public:

		MyMatrix() = delete;

		/**
		 * Die Konstrukter der Klasse, vorbereitet die Matrix auf Verwendung.
		 *
		 * @param[in] row		Die Anzhal der Zeilen innerhalb der Klasse
		 * @param[in] column	Die Anzahl der Spalten innerhalb der Klasse
		 * @param[in] value		Alle Elementen des Matrices weden auf dieser Wert inicializiert, standardmäßig: 0.
		 */
		MyMatrix(unsigned int row, unsigned int column, T value = 0);

		/**
		 * Die Copykonstruktor der Klasse, nimmt ein schon existierende Matrix und kopiert es.
		 *
		 * @param[in] other		Ein schon existierende Matrix, das wir kopieren möchten.
		 */
		MyMatrix(const MyMatrix<T>& other);

		/**
		 * Die Destruktor der Klasse, löscht die dynamisch allokierte Speicherplatz.
		 */
		~MyMatrix() { delete[] pMatrix; };

		/**
		 * Indexierung und Zugriff des Matrices wird durch die () Operator verwirklicht.
		 *
		 * @param[in] row		Die Zeilenzahl
		 * @param[in] column	Die Spaltenzahl
		 *
		 * @return				Referenz auf das gegebenen Element
		 */
		T& operator()(unsigned int row, unsigned int column);

		/**
		 * Indexierung des Matrices wird durch die () Operator verwirklicht.
		 *
		 * @param[in] row		Die Zeilenzahl
		 * @param[in] column	Die Spaltenzahl
		 *
		 * @return				Wert des gegebenen Elements
		 */
		T operator()(unsigned int row, unsigned int column) const;

		/**
		 * Gibt die Anzahl der Zeilen innerhalb die Matrix zürück.
		 *
		 * @return				Anzahl der Zeilen
		 */
		unsigned int rows() const { return m_row; };

		/**
		 * Gibt die Anzahl der Spalten innerhalb die Matrix zürück.
		 *
		 * @return				Anzahl der Spalten
		 */
		unsigned int columns() const { return m_column; };

		/**
		 * Überladene Zuweisungsoperator auf zwei Matricen.
		 *
		 * @param[in] other		Ein Matrix mit gleicher Typ
		 *
		 * @return				Referenz auf die lvalue mit neuer Wert
		 */
		MyMatrix<T>& operator=(const MyMatrix<T>& other);

		/**
		 * Überladene Additionsoperator auf zwei Matricen.
		 *
		 * @param[in] other		Ein Matrix mit gleicher Typ
		 *
		 * @return				Ergibnismatrix als Wert
		 */
		MyMatrix<T> operator+(const MyMatrix<T>& other) const;

		/**
		 * Überladene Additionsoperator mit Zuweisung.
		 *
		 * @param[in] other		Ein Matrix mit gleicher Typ
		 *
		 * @return				Referenz auf die lvalue mit neuer Wert
		 */
		MyMatrix<T>& operator+=(const MyMatrix<T>& other);

		/**
		 * Überladene Multiplikationsoperator
		 *
		 * @param[in] other		Ein Wert, die die gleiche Typ hat als die Elementen des Matrices
		 *
		 * @return				Ergebnismatrix als Wert
		 */
		MyMatrix<T> operator*(T other) const;

		/**
		 * Überladene Multiplikationsoperator mit Zuweisung.
		 *
		 * @param[in] other		Ein Wert, die die gleiche Typ hat als die Elementen des Matrices
		 *
		 * @return				Ergebnismatrix als Referenz
		 */
		MyMatrix<T>& operator*=(T other);

		/**
		 * Matrixmultiplikation.
		 *
		 * @param[in] other		Ein Matrix mit gleicher Typ
		 *
		 * @return				Ergebnismatrix als Wert
		 */
		MyMatrix<T> operator*(const MyMatrix<T>& other) const;

		/**
		 * Matrixmultiplikation mit Zuweisung.
		 *
		 * @param[in] other		Ein Matrix mit gleicher Typ
		 *
		 * @return				Ergebnismatrix als Referenz
		 */
		MyMatrix<T>& operator*=(const MyMatrix<T>& other);

		/**
		 * Addition von zwei Zeilen.
		 *
		 * @param[in] row_dest		Zeilenindex der Zeile, zu der die andere addiert wird
		 * @param[in] row_source	Zeilenindex der Zeile, die zu der andere addiert wird
		 *
		 * @return				Ergebnismatrix als Referenz
		 */
		MyMatrix<T>& rowAdd(unsigned int row_dest, unsigned int row_source);

		/**
		 * Zeilenmultiplikation mit einer Wert.
		 * 
		 * @param[in] row_dest	Zeilenindex der Zeile, die mit der Wert multipliziert wird
		 * @param[in] value		Mit dieser Wert wird die Zeile multipliziert
		 *
		 * @return				Ergebnismatrix als Referenz
		 */
		MyMatrix<T>& rowMult(unsigned int row_dest, T value);

		/**
		 * Vertauschen von zwei Zeilen.
		 * 
		 * @param[in] row1		Zeilenindex einer Zeile
		 * @param[in] row2		Zeilenindex der andere Zeile
		 *
		 * @return				Ergebnismatrix als Referenz
		 */
		MyMatrix<T>& rowInterchange(unsigned int row1, unsigned int row2);

		/**
		 * Transponierung des Matrix.
		 * 
		 * @return				Ergebnismatrix als Wert.
		 */
		MyMatrix<T> transposition() const;

		/**
		 * Gibt die Rank des Matrix zürück.
		 *
		 * @return				Rank des Matrix
		 */
		unsigned int rank();

		/**
		 * Gibt die Determinante des Matrix zürück.
		 *
		 * @return				Determinante des Matrix
		 */
		T determinant();
	};

	template<typename T>
	MyMatrix<T>::MyMatrix(unsigned int row, unsigned int column, T value) {
		if (!std::is_arithmetic<T>::value) {
			throw std::exception("Trying to create a Matrix with non-arithmetic elements.");
		}

		m_row = row;
		m_column = column;
		unsigned int size = m_row * m_column;
		pMatrix = new T[size];

		for (unsigned int i = 0u; i < size; i++) {
			pMatrix[i] = value;
		}
	}

	template<typename T>
	MyMatrix<T>::MyMatrix(const MyMatrix<T>& other) {
		m_row = other.m_row;
		m_column = other.m_column;
		unsigned int size = m_row * m_column;
		pMatrix = new T[size];

		for (unsigned int i = 0u; i < size; i++) {
			pMatrix[i] = other.pMatrix[i];
		}
	}

	template<typename T>
	T& MyMatrix<T>::operator()(unsigned int row, unsigned int column) {
		if (m_row <= row || m_column <= column) {
			throw std::exception("Out of range");
		}

		return pMatrix[row * m_column + column];
	}

	template<typename T>
	T MyMatrix<T>::operator()(unsigned int row, unsigned int column) const {
		if (m_row <= row || m_column <= column) {
			throw std::exception("Out of range");
		}

		return pMatrix[row * m_column + column];
	}

	template<typename T>
	MyMatrix<T>& MyMatrix<T>::operator=(const MyMatrix<T>& other) {
		if (this != &other) {
			m_row = other.m_row;
			m_column = other.m_column;
			delete[] pMatrix;

			pMatrix = new T[m_row * m_column];

			for (unsigned int i = 0u; i < m_row; i++) {
				for (unsigned int j = 0u; j < m_column; j++) {
					pMatrix[i * m_column + j] = other(i, j);
				}
			}
		}
		return *this;
	}

	template<typename T>
	MyMatrix<T> MyMatrix<T>::operator+(const MyMatrix<T>& other) const {
		if (m_row != other.m_row) {
			throw std::exception("Addition err: rows != other.rows");
		}
		if (m_column != other.m_column) {
			throw std::exception("Addition err: column != other.column");
		}

		MyMatrix<T> sum(m_row, m_column, 0);
		for (unsigned int i = 0u; i < sum.rows(); i++) {
			for (unsigned int j = 0u; j < sum.columns(); j++) {
				sum(i,j) = pMatrix[i * m_column + j] + other(i,j);
			}
		}
		
		return sum;
	}

	template<typename T>
	MyMatrix<T>& MyMatrix<T>::operator+=(const MyMatrix<T>& other) {
		return *this = *this + other;
	}

	template<typename T>
	MyMatrix<T> MyMatrix<T>::operator*(T other) const {
		MyMatrix<T> newM(m_row, m_column, 0);
		for (unsigned int i = 0u; i < m_row; i++) {
			for (unsigned int j = 0u; j < m_column; j++) {
				newM(i, j) = pMatrix[i * m_column + j] * other;
			}
		}
		return newM;
	}

	template<typename T>
	MyMatrix<T>& MyMatrix<T>::operator*=(T other) {
		return *this = *this * other;
	}

	template<typename T>
	MyMatrix<T> MyMatrix<T>::transposition() const {
		MyMatrix<T> newM(m_column, m_row, 0);

		for (unsigned int i = 0u; i < m_row; i++) {
			for (unsigned int j = 0u; j < m_column; j++) {
				newM(j, i) = pMatrix[i * m_column + j];
			}
		}

		return newM;
	}

	template<typename T>
	MyMatrix<T> MyMatrix<T>::operator*(const MyMatrix<T>& other) const {
		if (m_column != other.m_row) {
			throw std::exception("m_column != other.m_row");
		}

		MyMatrix<T> newM(m_row, other.m_column, 0);

		for (unsigned int i = 0u; i < m_row; i++) {
			for (unsigned int j = 0u; j < other.m_column; j++) {
				for (unsigned int k = 0u; k < m_column; k++) {
					newM(i, j) += pMatrix[i * m_column + k] * other(k, j);
				}
			}
		}

		return newM;
	}

	template<typename T>
	MyMatrix<T>& MyMatrix<T>::operator*=(const MyMatrix<T>& other) {
		return *this = *this * other;
	}

	template<typename T>
	MyMatrix<T>& MyMatrix<T>::rowAdd(unsigned int row_dest, unsigned int row_source) {
		if (row_dest >= m_row || row_source >= m_row) {
			throw std::exception("row index out of bounds");
		}

		for (unsigned int j = 0; j < m_column; j++) {
			pMatrix[row_dest * m_column + j] += pMatrix[row_source * m_column + j];
		}

		return *this;
	}

	template<typename T>
	MyMatrix<T>& MyMatrix<T>::rowMult(unsigned int row_dest, T value) {
		if (row_dest >= m_row){
			throw std::exception("row index out of bounds");
		}

		for (unsigned int j = 0; j < m_column; j++) {
			pMatrix[row_dest * m_column + j] *= value;
		}

		return *this;
	}

	template<typename T>
	MyMatrix<T>& MyMatrix<T>::rowInterchange(unsigned int row1, unsigned int row2) {
		if (row1 >= m_row || row2 >= m_row) {
			throw std::exception("row index out of bounds");
		}

		MyMatrix<T> newM(*this);

		for (unsigned int j = 0u; j < m_column; j++) {
			newM(row1, j) = pMatrix[row2 * m_column + j];
			newM(row2, j) = pMatrix[row1 * m_column + j];
		}

		*this = newM;

		return *this;
	}

	template<typename T>
	unsigned int MyMatrix<T>::rank() {
		MyMatrix<T> newM(*this);
		unsigned int rank = m_column > m_row ? m_row : m_column; // max rank = min(row,col)

		for (unsigned int row = 0u; row < rank; row++) {
			if (newM(row,row)) {
				for (unsigned int col = 0u; col < m_row; col++) {
					if (col != row) {

						double mult = (double)newM(col, row) /
							newM(row, row);
						for (unsigned int i = 0; i < rank; i++)
							newM(col, i) -= T(mult * newM(row, i));
					}
				}
			}
			else {
				bool reduce = true;

				for (unsigned int i = row + 1; i < m_row; i++) {
					if (newM(i, row)) {
						newM.rowInterchange(row, i);
						reduce = false;
						break;
					}
				}

				if (reduce) {
					rank--;

					for (unsigned int i = 0; i < m_row; i++) {
						newM(i, row) = newM(i, rank);
					}
				}
				row--;
			}
		}
		return rank;
	}

	template<typename T>
	T MyMatrix<T>::calcdet(MyMatrix<T> matrix, unsigned int n) {
		T det = 0;
		MyMatrix<T> submatrix(n, n);

		if (n == 1) {
			return matrix(0, 0);
		}
		else if (n == 2) {
			det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);		// a*c - b*d
			return det;
		}
		else {
			for (unsigned int x = 0u; x < n; x++) {
				unsigned int subi = 0;
				for (unsigned int i = 1u; i < n; i++) {
					unsigned int subj = 0;
					for (unsigned int j = 0; j < n; j++) {
						if (j != x) {
							submatrix(subi,subj) = matrix(i,j);		// Unterdeterminante
							subj++;
						}
					}
					subi++;
				}
				det = det + T((pow(-1, x) * matrix(0,x) * calcdet(submatrix, n - 1)));
			}
		}
		return det;
	}

	template<typename T>
	T MyMatrix<T>::determinant() {
		if (m_row != m_column) {
			throw std::exception("The matrix is not a square matrix, can't calculate determinant");
		}
		return calcdet(*this, m_column);
	}
}

/**
 * Globale Überladung von << Operator um die Ausschreibung des Matrix zu verwirklichen.
 *
 * @param[in] os		ostream Objekte
 * @param[in] m			eine Matrix
 *
 * @return				Refernz auf die ostream Objekte
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const GHA::MyMatrix<T>& m) {
	for (unsigned int i = 0u; i < m.rows(); i++) {
		for (unsigned int j = 0u; j < m.columns(); j++) {
			os << m(i, j) << '\t';
		}
		os << '\n';
	}

	return os;
}

/**
 * Globale Überladung von * Operator um die Multiplikation in Form von: scalar * matrix zu verwirklichen.
 *
 * @param[in] os		ostream Objekte
 * @param[in] m			eine Matrix
 *
 * @return				Ergebnismatrix als Wert
 */
template<typename T>
GHA::MyMatrix<T> operator*(T value, GHA::MyMatrix<T>& m) {
	unsigned int rows = m.rows();
	unsigned int columns = m.columns();
	GHA::MyMatrix<T> newM(rows, columns, 0);

	for (unsigned int i = 0u; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			newM(i, j) = value * m(i, j);
		}
	}

	return newM;
}
#endif // !_MYMATRIX_