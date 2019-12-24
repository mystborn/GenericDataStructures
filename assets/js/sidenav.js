$("table").toggleClass("table").toggleClass("table-hover");

const sidenavToggler = $(".side-nav-button");
const sidenavContainer = $("#sidenav-container");
const screenSmall = window.matchMedia("(min-width: 768px)");

function onScreenChange() {
    console.log(screenSmall.matches);
    if (screenSmall.matches) {
        if (!sidenavContainer.hasClass("show")) {
            sidenavContainer.toggleClass("show");
        }
    } else if (sidenavContainer.hasClass("show")) {
        sidenavContainer.toggleClass("show");
    }
}

onScreenChange(screenSmall);
screenSmall.addEventListener("change", onScreenChange);


const dropdowns = document.getElementsByClassName("nav-dropdown");

for (let i = dropdowns.length - 1; i >= 0; i--) {
    dropdowns[i].addEventListener("click", function() {
        this.classList.toggle("active");
        let dropdownContent = this.nextElementSibling;
        if (dropdownContent.style.display === "block") {
            dropdownContent.style.display = "none";
        } else {
            dropdownContent.style.display = "block";
        }
    });
}

const search = document.getElementById("search");
const navItems = document.getElementById("nav-items");
const navLinks = $("#nav-items").find("a");
const searchResults = document.getElementById("search-results");

let searchTerms = [];
for (let i = navLinks.length - 1; i >= 0; i--) {
    searchTerms.push({ text: navLinks[i].innerText, normalizedText: navLinks[i].innerText.toLowerCase(), link: navLinks[i].href });
}

searchTerms.sort(function(left, right) {
    return left.normalizedText.localeCompare(right.normalizedText);
});

search.addEventListener("input", function(search) {
    let normalized = search.target.value.toLowerCase();
    if(normalized === "") {
        navItems.style.display = "";
        searchResults.style.display = "none";
        return;
    } else if (navItems.style.display === "") {
        navItems.style.display = "none";
        searchResults.style.display = "";
    }

    let result = "";
    for (let i = searchTerms.length - 1; i >= 0; i--) {
        // console.log(`${searchTerms[i].normalizedText} includes ${normalized}? ${searchTerms[i].normalizedText.includes(normalized)}`);
        if (searchTerms[i].normalizedText.includes(normalized)) {
            result = result.concat("<li><a href=\"", searchTerms[i].link, "\">", searchTerms[i].text, "</a></li>\n");
        }
    }

    if (result === "") {
        result = "<li>No results found</li>";
    }

    searchResults.innerHTML = result;
});